#include <stdio.h>

/*
	T(ok): 分支可预测时, 调用函数花费的时钟周期
	T(ran): 分支不可预测时, 调用函数花费的时钟周期
	T(mp): 分支预测错误时, 处罚的时钟周期
	T(avg): 调用函数平均花费的时钟周期
	p: 发生分支预测错误的概率, 一般是50%, 也就是0.5

	T(avg)= T(ran) = T(ok) + pT(mp)
	T(mp) = 1/p * (T(ran) - T(ok)) 
	
*/
int test() {
	/*
		一个比较旧的处理器模型上运行，当分支行为模式非常可预测时，我们的代码需要大约16 个时钟周期，
		而当模式是随机的时候，需要大约 31 个时钟周期。

		A. 预测错误处罚大约是多少？
		T(mp) = 1/0.5 (T(ran) - T(ok)) = 2 * (31 - 16) = 30;
		
		
		
		B. 当分支预测错误时，这个函数需要多少个时钟周期？
		
		当分支预测错误时, 花费的时钟周期是: 16 + 30 = 46;
	
	
	
	
	
	
	*/
}