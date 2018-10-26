template <class T>
class Vector
{
protected:
		int l;
		T* m;
public:
	TVector(int n = 0);
	TVector(TVector(<T>&A);
	virtual T&operator[](int n);
	virtual TVector <T> &operator = (TVector <T> &A);
	virtual TVector <T> operator + (TVector <T> &A);
	virtual TVector <T> operator - (TVector <T> &A);
	virtual TVector <T> operator * (TVector <T> &A);
	virtual TVector <T> &operator == (TVector <T> &A
}