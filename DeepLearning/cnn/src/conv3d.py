import numpy as np
import tensorflow as tf

img_tensor = tf.constant(
    [
        [
            [[0,1,1], [1,2,0], [3,3,3], [1,1,1], [0,0,0]],
            [[2,2,2], [3,0,3], [1,3,1], [0,0,0], [1,1,1]],
            [[2,2,2], [0,0,0], [1,1,1], [2,0,2], [1,1,1]],
            [[1,1,1], [0,2,0], [0,0,0], [2,1,1], [0,0,0]],
            [[0,0,0], [1,1,1], [1,2,2], [1,1,1], [1,1,1]]
        ]
    ]) # yapf: disable
# [batch, in_depth, in_height, in_width, in_channels]
print(img_tensor.shape) # (1, 5, 5, 3), 一张 5*5 3通道的图片

filter_tensor = tf.constant(
    [
        [
            [[0],[-1],[0]], 
            [[-1],[1],[1]], 
            [[0],[0],[0]]
        ]
        ,
        [
            [[1],[1],[1]], 
            [[0],[0],[-1]], 
            [[1],[0],[1]]
        ]
        ,
        [
            [[0],[0],[0]], 
            [[1],[1],[1]], 
            [[0],[0],[0]]
        ]
    ]
)# yapf: disable
# [filter_depth, filter_height, filter_width, in_channels,out_channels]
print(filter_tensor.shape) # (3, 3, 3, 1) ,3*3 filter, 3channel, 1个

# result = tf.nn.conv2d(img_tensor,
#                       filter_tensor,
#                       strides=[1, 1, 1, 1],
#                       padding='VALID')
# print(result)