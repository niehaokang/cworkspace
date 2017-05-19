#include<iostream>
#include<iomanip>
double legend(int P, int Q, int N, int propability, int I, int thresh, long double init);
using namespace std;
int main()
{
    int P, Q, N;
    cin >>P>>Q>>N;

    int num = 100 / Q + 1;
    long double *state = new long double[num];
    int tmp = 2;
    int depth=0;
    for(int i=1;i<8;i++)
        if(tmp>P){
            depth=i;
            break;
        }
        else
            tmp *= 2;
    state[0] = 0;
    for(int i=num-1;i>=0;i--)
        if(i==num-1){
            state[i] = 2+state[0]-(i*Q)/100.0;
        }
        else if(i==0){
            state[i] = 1 + state[1]; 
        }
        else{
            state[i] = (i*Q)/100.0*(1+state[0]) + (100-i*Q)/100.0 * (1+state[i+1]);
        }
    state[0] = state[0] * (N -depth);
    long double result = 0;
    if(N<=depth)
        result = legend(P, Q, N, P, 2, 0, 0);
    else
        result = legend(P, Q, N, P, 2, N-depth, state[0]);
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2);
    cout<<result;
    return 0;
};
double legend(int P, int Q, int N, int propability, int I, int thresh, long double init)
{
    if(N==thresh) return init;
    if(propability>=100) return 1+legend(P, Q, N-1, int(P/I), 2*I, thresh, init);
    return propability/100.0*(1+legend(P, Q, N-1, int(P/I), 2*I, thresh, init)) + (100-propability)/100.0*(1+legend(P, Q, N, propability+Q, I, thresh, init));
};
