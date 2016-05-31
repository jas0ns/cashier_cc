#Cashier

###Development Evironment
Ubuntu 14.04 
Vim 
g++ 4.8.2

###Usage
参考main.cc中的用法<br>
1)初始化商品列表`Init_Commodity_Map_From_Dir`<br>
2)初始化购物车`InitShoppingCartFromString`<br>
3)计算金额`CalculateTotalPriceAndAllowance`<br>
4)生成发票详细部分、优惠部分和总计部分`GenerateInvoiceParts`<br>
5)生成最终发票`GenerateInvoice`<br>
6)打印

###Build
编译所有单元测试用例: 进入make目录下执行 `make test`<br>
运行所有单元测试用例：`./test.sh`<br>
编译main：进入make目录下执行`make`<br>
运行main: `./cashier`<br>

###Features
1)根据配置文件添加更改商品信息和优惠活动<br>
2)各模块可单独使用<br>
3)易于增加不同种类优惠活动<br>

###Add new promotions
1) 继承Promotions，实现CalculatePromotions函数<br>
2) 指定type、name、print、arguments，其中，type为int类型，用于标志优惠类型，name用于指定优惠活动名字，
print用于打印，arguments用于解析自定义优惠参数<br>
3) 修改GetPromotionsInstance工厂方法，增加新的case段。<br>

###TODO
1) 增加从文件读条形码<br>
2) 修改为循环接受请求<br>
3) 增加多种优惠活动<br>

###Shortage
1) 每种商品只能添加一种优惠活动。<br>
2) 增加优惠活动需要修改少部分代码。<br>
3) 测试用例不完善<br> 
4) 数据格式没有完全按照作业要求（开始读题不仔细，道歉）<br>

###BTW
时间紧张，健壮性欠考虑。

