import numpy as np
from pprint import pprint


class BPNetwork(object):
    """
    define network
    """
    def __init__(self, nInput, nHidden, nOutput, lr):
        self.nInput = nInput  # num of input node
        self.nHidden = nHidden  # num of hidden node
        self.nOutput = nOutput  # num of output node
        self.lr = lr  # learning rate
        print("-- nInput ",self.nInput)
        print("-- nHidden ",self.nHidden)
        print("-- nOutput ",self.nOutput)
        print("-- lr ",self.lr,self.lr.shape)

        # mnist shape: nInput=4,nHidden=5, nOutput=4
        # W1.shape=(5,2)
        self.W1 = np.random.normal(
            loc=0.0,  # μ
            scale=self.nHidden**(-0.5),  # σ
            size=(self.nHidden, self.nInput)  # size
        )
        print("-- W1.shape",self.W1.shape)
        # W2.shape=(4,5)
        self.W2 = np.random.normal(0.0, self.nOutput**(-0.5),
                                   (self.nOutput, self.nHidden))
        print("-- W2 shape",self.W2.shape)

        # activation: sigmoid
        self.activation = (lambda x: 1 / (1 + np.exp(-x)))  # sigmoid

        self.total_loss = 0

    def train(self, inputs_org, groundtruth_org):
        # resize input.shape=(2,1)
        inputs = np.array(inputs_org, ndmin=2).T  # .T

        # groundtruth.shape=(4,1)
        groundtruth = np.array(groundtruth_org, ndmin=2).T

        # Forward propagation
        hid_ints = np.dot(self.W1, inputs)  # W1X1, hid_ints.shape=(5,1)
        hid_outs = self.activation(hid_ints)  # f(W1X1), hid_outs.shape=(5,1)
        out_outs = np.dot(self.W2, hid_outs)  # f(W1X1)X2, out_ints.shape=(4,1)

        # Back propagation (!! too difficult !!)
        loss = (out_outs - groundtruth)**2  # loss.shape=(4,1)
        self.total_loss = np.sum(loss) / loss.shape[0]
        hid_error = np.dot(loss.T, self.W2) * (hid_outs * (1 - hid_outs)).T
        # hid_error.shape=((1,4).(4,5))*((5,1)*(5,1)).T=(1,5)

        self.W2 += loss * hid_outs.T * self.lr  # shape=(4,5)
        self.W1 += (inputs * hid_error * self.lr).T  # shape=(5,2)

    def inference(self, inputs_org):
        inputs = np.array(inputs_org, ndmin=2).T

        hid_ints = np.dot(self.W1, inputs)
        hid_outs = self.activation(hid_ints)

        out_outs = np.dot(self.W2, hid_outs)

        return out_outs

    def getTotalLoss(self):
        return self.total_loss


if __name__ == "__main__":
    inputs_org = [[0,0],[0,1],[1,0],[1,1]]  # input
    groundtruth_org = [0,0,0,1]  # label

    network = BPNetwork(nInput=len(inputs_org),
                        nHidden=10,
                        nOutput=len(groundtruth_org),
                        lr=0.001)

    epoch = 0
    epoch_list = []
    loss_list = []
    while (1):
        network.train(inputs_org, groundtruth_org)
        out = network.inference(inputs_org)
        loss = network.getTotalLoss()
        epoch_list.append(epoch)
        loss_list.append(loss)

        if (epoch % 1000 == 0):
            print(
                epoch, "  -- out: %8f %8f %8f %8f" %
                (out[0][0], out[1][0], out[2][0], out[3][0]), "\t-- loss: ",
                (loss))

        epoch += 1
        if (loss < 1e-5):
            break

    print(" ------  Train result ------")
    print("  epoch ", epoch)
    print("  loss ", loss_list[-1])
    out = network.inference(inputs_org)
    print("  out   %8f %8f %8f %8f" %
          (out[0][0], out[1][0], out[2][0], out[3][0]))

    from matplotlib import pyplot as plt
    plt.plot(epoch_list, loss_list)
    plt.show()
