#include <iostream>

template < class Z >
class Foo {
    // general realization of template Foo
};

template < class T >
class Foo < T*> {
    // special realization of Foo for pointers
};


class Fraction {
private:
    // Calculates the greates common divisor with
    // Euclid's algorithm
    // both arguments have to be positive
    long long gcd(long long a, long long b) {
        while (a != b) {
            if (a > b) {
                a -= b;
            }
            else {
                b -= a;
            }
        }
        return a;
    }

public:
    long long numerator, denominator;

    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    Fraction(long long n) {
        numerator = n;
        denominator = 1;
    }

    Fraction(long long n, long long d) {
        if (d == 0) {
            std::cerr << "Denominator may not be 0." << std::endl;
            exit(0);
        }
        else if (n == 0) {
            numerator = 0;
            denominator = 1;
        }
        else {
            int sign = 1;
            if (n < 0) {
                sign *= -1;
                n *= -1;
            }
            if (d < 0) {
                sign *= -1;
                d *= -1;
            }

            long long tmp = gcd(n, d);
            numerator = n / tmp * sign;
            denominator = d / tmp;
        }
    }

    operator int() { return (numerator) / denominator; }
    operator float() { return ((float)numerator) / denominator; }
    operator double() { return ((double)numerator) / denominator; }

    friend std::istream& operator>>(std::istream&, Fraction& );

    friend std::ostream& operator<<(std::ostream& strm, const Fraction& a) {
        if (a.denominator == 1) {
            strm << a.numerator;
        }
        else {
            strm << a.numerator << "/" << a.denominator;
        }
        return strm;
    }
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator
        + rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator);
    return tmp;
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator
        + rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator
        - rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator);
    return tmp;
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator
        - rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator * rhs.numerator,
        lhs.denominator * rhs.denominator);
    return tmp;
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator * rhs.numerator,
        lhs.denominator * rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(int lhs, const Fraction& rhs) {
    Fraction tmp(lhs * rhs.numerator, rhs.denominator);
    return tmp;
}

Fraction operator*(const Fraction& rhs, int lhs) {
    Fraction tmp(lhs * rhs.numerator, rhs.denominator);
    return tmp;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator,
        lhs.denominator * rhs.numerator);
    return tmp;
}



std::istream& operator>>(std::istream& ot, Fraction& a) {
    ot >> a.numerator; std::cout << "\\";
    ot >> a.denominator;
    return ot;
}

template < class T >
bool sort_less(T a, T b) {
    return a < b;
}
template < >
bool sort_less < const char* >(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}


// Puzirek for int
void sort_int(int* array, int len) {
	for (int start = 0; ; start++) {
		bool done = true;
		for (int i = len - 2; i >= start; i--) {
			if (array[i + 1] < array[i]) {
				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				done = false;
			}
		}
		if (done)
			break;
	}
}
// Puzirek for any
template < class T >
void sort(T * array, int len) {
	for (int start = 0; ; start++) {
		bool done = true;
		for (int i = len - 2; i >= start; i--)
			if (sort_less(array[i + 1], array[i])) {
			T tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			done = false;
		}
		if (done)
			break;
	}
}

template <class T > class QMatrix {
	T * *element; // elements array
	int N; // matrix size
public:
	QMatrix(int n = 0);
	//QMatrix(const QMatrix <T >&);
	//~QMatrix();
	//int GetSize() const;
	QMatrix <T > operator +(const QMatrix <T>&) const;
	//QMatrix <T > operator *(const QMatrix <T >&) const;
	//QMatrix <T > operator =(const QMatrix <T >&) const;
	//QMatrix <T > SubMatrix(int, int) const; // minor
	//QMatrix <T > Inverse() const; // inverse matrix
	//T Determinant() const;
    template <class T>
    friend std::istream& operator>>(std::istream&, QMatrix<T>&);
    template <class T>
    friend std::ostream& operator<<(std::ostream&, const QMatrix<T>&);

};


int main(void) {
	int int_arr[5] = { 5, 21, 2, 39, 0 };
	double double_arr[5] = { 12.1, 12.0, 43.22, 3, 9.09 };
    char char_arr[5] = { 'g', 's', 'a', 'v', 'z' };
	std::cout << "No sorted int arr:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << int_arr[i] << " ";
	}
	std::cout << std::endl << "Sorted int arr:" << std::endl;
	sort(int_arr, 5);
	for (int i = 0; i < 5; i++) {
		std::cout << int_arr[i] << " ";
	}
	std::cout << std::endl << "No sorted double arr:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << double_arr[i] << " ";
	}
	std::cout << std::endl << "Sorted double arr:" << std::endl;
	sort<double>(double_arr, 5);
	for (int i = 0; i < 5; i++) {
		std::cout << double_arr[i] << " ";
	}
    std::cout << std::endl << "No sorted char arr:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << char_arr[i] << " ";
    }
    std::cout << std::endl << "Sorted char arr:" << std::endl;
    sort<char>(char_arr, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << char_arr[i] << " ";
    }

	//work!
    QMatrix<Fraction> A(3);
    std::cout << "Write QMatrix A:" << std::endl;
    std::cin >> A;
    std::cout << "Yout QMatrix A:" << std::endl;
    std::cout << A;

	return 000;
}

template < class T >
QMatrix<T>::QMatrix(int n) {
	N = n;
	element = new T * [N];
	for (int i = 0; i < N; i++)
		element[i] = new T[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		element[i][j] = 1;
}

template < class T >
QMatrix<T> QMatrix<T>::operator +(const QMatrix <T > &second) const {
	if (second.N == N) {
			QMatrix <T > tmp(N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			tmp.element[i][j] = element[i][j] + second .
			element[i][j];
		return tmp;
	}
	else
		throw 1;
}

template <class T>
std::istream& operator>>(std::istream& in, QMatrix<T> &ob) {
    if (ob.N != 0) {
        for (int i = 0; i < ob.N; i++)
            for (int j = 0; j < ob.N; j++)
            in >> ob.element[i][j];
    }
    return in;
}

template <class T>
std::ostream& operator<<(std::ostream& out,const QMatrix<T> &ob) {
    if (ob.N != 0) {
        out << " Matrix : " << std::endl;
        for (int i = 0; i < ob.N; i++) {
                for (int j = 0; j < ob.N; j++)
                    out << ob.element[i][j] << "\t";
                out << std::endl;
        }
    }
    else
        out << " Matrix is empty " << std::endl;
    return out;
}
