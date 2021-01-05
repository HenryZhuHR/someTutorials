import numpy as np
import tensorflow as tf

img_tensor = tf.constant([[[[1], [2], [3], [1], [0]], [[2], [3], [3], [0],
                                                       [1]],
                           [[2], [0], [1], [2], [1]], [[1], [2], [0], [1],
                                                       [0]],
                           [[0], [1], [2], [1], [1]]]])
print(img_tensor)
filter_tensor = tf.constant([[[[0]], [[1]], [[0]]], [[[1]], [[0]], [[1]]],
                             [[[0]], [[1]], [[0]]]])
print(filter_tensor)

result = tf.nn.conv2d(img_tensor,
                      filter_tensor,
                      strides=[1, 2, 2, 1],
                      padding='VALID')
import pprint
pprint.pprint(result)