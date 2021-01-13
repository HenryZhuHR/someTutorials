from tqdm import tqdm
import pip, torch, argparse
import numpy as np
import torch, os

depths  =[8, 16, 32, 48]
wsl = [f'resnext101_32x{i}d_wsl' for i in depths]
model_paths = dict(zip(depths, wsl))

def resnext101(depth = 32):
    md = torch.hub.load('facebookresearch/WSL-Images', model_paths[depth])
    """
        Downloading: "https://github.com/facebookresearch/WSL-Images/archive/master.zip" to C:\Users\henryzhu/.cache\torch\hub\master.zip
        Downloading: "https://download.pytorch.org/models/ig_resnext101_32x32-e4b90b00.pth" to C:\Users\henryzhu/.cache\torch\hub\checkpoints\ig_resnext101_32x32-e4b90b00.pth
    """
    md.fc = torch.nn.Linear(md.fc.in_features, 2)
    return md

if __name__ == "__main__":
    model=resnext101()
    print(model)

