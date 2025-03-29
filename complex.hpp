#pragma once 

template<typename R> requires std::is_floating_point_v<R>
class complex
{
    R c_re, c_im;
    
public:

    /* Costruttore di default: restituisce unità immaginaria */
    complex()
        : c_re(0), c_im(1)
    {}


    /* User-defined constructor. Takes two parameters, real part and
    * imaginary part */
    complex(R r, R i)
        : c_re(r), c_im(i)
    {}

    /* Metodo per ottenere parte reale */
    R real(void) const {
        return c_re;
    }

    /* Metodo per ottenere parte immaginaria */
    R im(void) const {
        return c_im;
    }

    /* Metodo per ottenere complesso coniugato */
    complex conjugate(void) const {
        return complex(c_re, -c_im);
    }


    /* Define the += operator between complex numbers. */
    complex operator+=(const complex& other) {
        R a = c_re;
        R b = c_im;
        R c = other.real();
        R d = other.im();
        c_re = a+c;
        c_im = b+d;
        return *this; // Returna il numero iniziale, che è però stato aggiornato sommando l'altro numero
    }

    /* Define operator+ in terms of operator +=. */
    complex operator+(const complex& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }

    /* Define the += operator between a complex and a real number*/
    complex operator+=(const R& other) {
        c_re += other;
        return *this;
    }

    /* Define operator+ in terms of operator += */
    complex operator+(const R& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }

    /* Define *= operator between complex numbers */
    complex operator*=(const complex& other) {
        R c_real = c_re;
        c_re = c_real*other.real() - c_im*other.im();
        c_im = c_im*other.real() + c_real*other.im();
        return *this;
    }

    /* Define operator* in terms of operator += */
    complex operator*(const complex& other) const {
        complex ret = *this;
        ret *= other;
        return ret;
    }

    /* Define *= operator between complex and real numbers */
    complex operator*=(const R& other) {
        c_re = c_re*other;
        c_im = c_im*other;
        return *this;
    }

    /* Define operator* in terms of operator += */
    complex operator*(const R& other) const {
        complex ret = *this;
        ret *= other;
        return ret;
    }
};

    /* Operatore di stampa; definito fuori dalla classe */
    /* Overload of <<, to make the complex printable. */
    template<typename R>
    // Uso ostream per renderlo utilizzabile con qualunque stream in uscita, non solo a schermo
    std::ostream& operator<<(std::ostream& os, const complex<R>& c) {
        if (c.im() >= 0)
        os << c.real() << "+" << c.im() << "i";
        else
        os << c.real() << c.im() << "i";

        return os;
    };
