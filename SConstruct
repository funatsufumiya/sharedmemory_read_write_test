# SConstruct
import os

env = Environment(CXX='g++')
env.Append(CXXFLAGS=['-std=c++17', '-Wall', '-Wextra', '-pedantic'])

# Homebrewのパスを確認
homebrew_path = '/opt/homebrew'
if os.path.exists(homebrew_path):
    print(f"Homebrew detected at {homebrew_path}")
    env.Append(CPPPATH=[f'{homebrew_path}/include'])
    env.Append(LIBPATH=[f'{homebrew_path}/lib'])
else:
    env.Append(CPPPATH=['/usr/local/include'])
    env.Append(LIBPATH=['/usr/local/lib'])

# libsharedmemoryのヘッダーファイルの場所を追加
env.Append(CPPPATH=['node_modules/cpp_libsharedmemory/include'])

# コンパイラフラグにインクルードパスを明示的に追加
env.Append(CXXFLAGS=[f'-I{inc}' for inc in env['CPPPATH']])

# ビルドターゲットの定義
env.Program('sharedmemory_writer', 'sharedmemory_writer.cpp')
env.Program('sharedmemory_reader', 'sharedmemory_reader.cpp')
