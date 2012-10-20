#include "ibniz.h"

Ibniz::Ibniz()
{
}

void Ibniz::run(QImage *src, QImage *dst, const QString &program, int cx, int cy)
{
	stack.clear();

	for(int y = 0; y < src->height(); y++)
		for(int x = 0; x < src->width(); x++)
		{
			stack.push( FIX_FROM_INT(y - cy) );
			stack.push( FIX_FROM_INT(x - cx) );

			parse(src, program, cx, cy);

			dst->setPixel(x, y, stack.pop());
		}
}

void Ibniz::parse(QImage *src, const QString &program, int cx, int cy)
{
	QByteArray str_data;
	char *str;

	fix_t a, b, c;
	fix_t value;

	int x;
	int y;

	value = 0;

	str_data = program.toAscii();
	str = str_data.data();

	while ( *str )
	{

		switch ( *str )
		{
			/* arithmetic */
			case '+':
				b = stack.pop();
				stack.push( fix_add(stack.pop(), b) );
				break;
			case '-':
				b = stack.pop();
				stack.push( fix_sub(stack.pop(), b) );
				break;
			case '*':
				b = stack.pop();
				stack.push( fix_mul(stack.pop(), b) );
				break;
			case '/':
				b = stack.pop();
				stack.push( fix_div(stack.pop(), b) );
				break;
			case '%':
				b = stack.pop();
				stack.push( fix_mod(stack.pop(), b) );
				break;

			case 'q':
				stack.push( fix_sqrt(stack.pop()) );
				break;

			/* trigonometry */
			case 'a':
				b = stack.pop();
				stack.push( fix_atan2(stack.pop(), b) );
				break;
			case 's':
				stack.push( fix_sin(stack.pop()) );
				break;
			case 'c':
				stack.push( fix_cos(stack.pop()) );
				break;
			case 'j': /* Y X - r phi */
				b = stack.pop();
				a = stack.pop();

				stack.push( fix_sqrt( fix_add(fix_mul(b, b), fix_mul(a, a)) ) );
				stack.push( fix_atan2(b, a) );
				break;

			case 'J': /* r phi - Y X */
				b = stack.pop();
				a = stack.pop();

				stack.push(fix_mul(a, fix_sin(b)));
				stack.push(fix_mul(a, fix_cos(b)));
				break;

			case 'b':
				b = stack.pop();
				stack.push( (b >= 0) ? b : -b );
				break;

			case '&':
				b = stack.pop();
				stack.push( stack.pop() & b );
				break;
			case '|':
				b = stack.pop();
				stack.push( stack.pop() | b );
				break;
			case '^':
				b = stack.pop();
				stack.push( stack.pop() ^ b );
				break;
			case '~':
				stack.push( ~stack.pop() );
				break;

			/*case '>':
				STACK_TOP = (*b > 0) ? *b : 0;
				break;
			case '<':
				STACK_TOP = (*b < 0) ? *b : 0;
				break;
			case '=':
				STACK_TOP = (*b == 0) ? 1 : 0;
				break;*/

			/* stack manipulation */
			case 'd':
				stack.push( stack.top() );
				break;
			case 'p':
				stack.pop();
				break;
			case 'x':
				b = stack.pop();
				a = stack.pop();

				stack.push(b);
				stack.push(a);
				break;
			case 'v':
				c = stack.pop();
				b = stack.pop();
				a = stack.pop();

				stack.push(b);
				stack.push(c);
				stack.push(a);
				break;

			case 'G':
				b = stack.pop();
				a = stack.pop();

				x = FIX_TO_INT(b) + cx;
				y = FIX_TO_INT(a) + cy;

				if (x >= 0 && x < src->width() && y >= 0 && y < src->height() )
					stack.push( src->pixel(x, y) );
				else
					stack.push( 0 );
				break;

			/* data */
			case '0':case '1':case '2':case '3':case '4':
			case '5':case '6':case '7':case '8':case '9':
				value <<= 4;
				value |= *str - '0';
				break;
			case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':
				value <<= 4;
				value |= *str - 'A' + 0xA;
				break;

			case '.':
				stack.push(value);
				value = 0;
				break;

			case ' ':
				/* nop */
				break;
		}

		str++;
	}
}
