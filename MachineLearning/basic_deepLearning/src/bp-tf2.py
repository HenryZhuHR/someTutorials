import tensorflow as tf
import numpy as np

x_ = tf.placeholder(tf.float32, shape=[4, 2], name='x-input')
y_ = tf.placeholder(tf.float32, shape=[4, 1], name='y-input')

w1 = tf.Variable(tf.random_normal([2, 2], -1, 1), name='weights1')
w2 = tf.Variable(tf.random_normal([2, 1], -1, 1), name='weights2')

b1 = tf.Variable(tf.zeros([2]), name='bias1')
b2 = tf.Variable(tf.zeros([1]), name='bias2')

z2 = tf.sigmoid(tf.matmul(x_, w1) + b1)
pred = tf.sigmoid(tf.matmul(z2, w2) + b2)

cost = tf.reduce_mean(
    ((y_ * tf.log(pred)) + ((1 - y_) * tf.log(1.0 - pred))) * -1)

learning_rate = 0.01
train_step = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)

XOR_X = [[0, 0], [0, 1], [1, 0], [1, 1]]
XOR_Y = [[0], [1], [1], [0]]

init = tf.initialize_all_variables()

with tf.Session() as sess:
    sess.run(init)
    write = tf.summary.FileWriter("./tb/XOR_logs", sess.graph)
    for i in range(100000):
        sess.run(train_step, feed_dict={x_: XOR_X, y_: XOR_Y})

    print("Final prediction ", sess.run(pred, feed_dict={
        x_: XOR_X,
        y_: XOR_Y
    }))
