extern double mean(double arr[], int n);

double variance(double arr[], int n) {
    if (n <= 1) return 0.0;
    double m = mean(arr, n);
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = arr[i] - m;
        sum += diff * diff;
    }
    return sum / (n - 1);
}
