import matplotlib.pyplot as plt
import numpy as np


def sigmoid(x):
    return 1./(1.+np.exp(-x))
def sgn(x):
    return 1 if (x>=0) else 0


if __name__ == "__main__":
    x=np.arange(-1,1,0.01)
    y=np.empty(x.shape)
    for i in range(len(x)):
        y[i]=sgn(x[i])
        print(y[i])
    
    # const=np.ones(y.shape)
    # plt.plot(x,const,'--')

    plt.plot(x,y,label='sgn')
    # plt.xlim([-10,10])
    plt.xlabel('input')
    plt.ylabel('ouput')
    plt.title('Sgn')
    plt.legend()
    plt.show()