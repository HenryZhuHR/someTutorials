/**
 *
 * @brief 打开文件   \n
 * 文件打开成功后，必须使用::CloseFile函数关闭
 * @param[in] fileName    文件名
 * @param[in] fileMode    文件模式，可以由以下几个模块组合而成：
 *     -r读取
 *     -w 可写
 *     -a 添加
 *     -t 文本模式(不能与b联用)
 *     -b 二进制模式(不能与t联用)
 * @return 返回文件编号
 *  --1表示打开文件失败(生成时:.-1)
 * @retval 0     成功
 * @retval -1    失败
 *
 * @note 文件打开成功后，必须使用::CloseFile函数关闭
 * @par 示例:
 * @code
 *        //用文本只读方式打开文件
 *        int ret = OpenFile("test.txt", "a");
 * @endcode
 * @see     函数::ReadFile::CloseFile
 * (“::”是指定有连接功能,可以看文档里的CloseFile变成绿,点击它可以跳转到CloseFile.)
 * @deprecated 由于特殊的原因，这个函数可能会在将来的版本中取消
 * @todo 还没有完成的工作和需要改进的工作
 *
 * @pre file 必须使用OpenFile的返回值
 * @example
 * OpenFile(const char* fileName, const char* fileMode)
 */
int OpenFile(const char* fileName, const char* fileMode);
