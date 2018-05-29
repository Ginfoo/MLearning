#pragma once
#include <cmath>
#include <vector>
using std::vector;

template <typename T>
class GKMeans
{
public:
	GKMeans<T>() = default;
	explicit GKMeans<T>(int k_value, int dim_value);
	~GKMeans<T>();

	void setK(int k_value);
	double getDistance(const double* x1, const double* x2) const;
	void 
private:
	int k;
	int dim;
	vector<T>* centeroid;
	double * temp_dist;
};

template <typename T>
GKMeans<T>::GKMeans(int k_value, int dim_value = 2) : k(k_value), dim(dim_value)
{
	this->centeroid = new vector<T>[k];
	this->temp_dist = new double[k];
}

template <typename T>
GKMeans<T>::~GKMeans()
{
	delete[] this->centeroid;
	delete[] this->temp_dist;
}

template <typename T>
void GKMeans<T>::setK(int k_value)
{
	this->k = k_value;
}

template <typename T>
double GKMeans<T>::getDistance(const double* x1, const double* x2) const
{
	double distance = 0;
	for (int i = 0; i < dim; ++i)
	{
		distance += pow(x1[i] - x2[i], 2);
	}
	return pow(distance, 1 / dim);
}
