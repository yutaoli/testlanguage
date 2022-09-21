
# 中国的收入分布是什么样的？
# https://zhuanlan.zhihu.com/p/146359406

###函数###
topN<-function(topN_c, income_rank){
  total_income<-sum(income_rank$total_income_aver_range*income_rank$count);
  total_people<-sum(income_rank$count)
  
  res<-NA
  for (i in seq_along(topN_c)){# 等价于1..length(topN_c)
    topN_i<-topN_c[i]
    j<-1
    sum_i_income<-0
    total<-0
    total_people*topN_i
    while (total<total_people*topN_i){
      total<-total+income_rank$count[j:j]
      sum_i_income<-sum_i_income+income_rank$total_income_aver_range[j:j]*income_rank$count[j:j]
      j<-j+1
    }
    
    res<-cbind(res,sum_i_income/total_income)
  }
  res<-res[c(-1)]#把第一列剔除
  return(res)
}

SumN<-function(count_c){
  res<-NA
  total<-0
  for (i in seq_along(count_c)){
    total<-total+count_c[i]
    
    if (i==1) {
      res<-cbind(res,count_c[i])
      next# 即continue;
    }
    
    res<-cbind(res,total)
  }
  res<-res[c(-1)]#把第一列剔除
  return(res)
}

GetDistbute<-function(income_c,sum_total_percentage,segment){#segment区间步长
  
  res<-NA
  res_percentage<-NA
  for (i in seq_along(income_c)){
    income_c_i <- income_c[i]
    if (income_c_i == 0){
      next
    }
    if(income_c_i - floor(income_c_i /segment)*segment == 0){# income_c_i  mod segment == 0
      res<-cbind(res,income_c_i)
      res_percentage<-cbind(res_percentage, sum_total_percentage[i])
    }
  }
  res<-res[c(-1)]#把第一列剔除
  res_percentage<-res_percentage[c(-1)]#把第一列剔除
  
  res<-data.frame(res,res_percentage)
  return (res)
}

###主程序###
#x<-c(3,4,6,7,8,9,10,100,3,4,6,7,8,9,10,100)
#y<-quantile(x,c(0.1,0.2,0.3,.4,.5,.6,.7,.8,.9,.95,.99,.999))
#y

library('haven')
library('sqldf')
library('reldist')

num<-200000
hh <- read_dta("e:/hh2017_20191120_version13(CHFS).dta",n_max=num)
master<-read_dta("e:/chfs2017_master_city_20191120.dta",n_max=10000*num)
#names(hh) #输出各colunm

###数据变换###
hh_income<-hh[c("hhid","total_income","a2000a")]
hh_income$total_income[hh_income$total_income<0]<-0
View(hh_income)
master_weight<-master[c("hhid", "swgt_p")]
master_weight<-sqldf("select hhid, avg(swgt_p) as swgt_p from master_weight group by hhid")
#View(master_weight)

hh_income_with_weight<-sqldf("select hh_income.hhid,total_income,a2000a,swgt_p from hh_income, master_weight where master_weight.hhid==hh_income.hhid")
View(hh_income_with_weight)

#家庭年收入
total_income<-hh_income_with_weight[c("total_income")]

#成员数
no_of_people<-hh_income_with_weight[c("a2000a")]+1 #"a2000a"：除受访者以外，还有几个家庭成员
no_of_people$a2000a[is.na(no_of_people$a2000a)]<-1 #NA默认是1
names(no_of_people)<-"no_of_people"
#View(total_income)

#家庭人均年收入
total_income_aver=total_income/no_of_people
names(total_income_aver)<-'total_income_aver'

#家庭人均年收入映射到收入区间
range=500
total_income_aver_range<-(floor((total_income_aver-1)/range) + 1)*range#把收入映射到range（如500）为一个单位上,(0,range],(range,2range],...)
names(total_income_aver_range)<-"total_income_aver_range"

#家庭人均年收入区间分布
hh_income_with_weight_w<-hh_income_with_weight[c("hhid","total_income","swgt_p")]
hh_income_with_weight_w<-cbind(hh_income_with_weight_w,no_of_people,total_income_aver,total_income_aver_range)
#hh_income_with_weight<-cbind(hh_income_with_weight,total_income_range)#加入一行
View(hh_income_with_weight_w)

total_income_aver_range_count=sqldf("select total_income_aver_range, count(*) as line_count,sum(swgt_p) as count from hh_income_with_weight_w group by total_income_aver_range order by total_income_aver_range asc")
total_percentage<-total_income_aver_range_count$count/sum(total_income_aver_range_count$count)#占比
sum_total_percentage<-SumN(total_percentage)
total_income_aver_range_count<-cbind(total_income_aver_range_count,total_percentage, sum_total_percentage)
View(total_income_aver_range_count)

res<-GetDistbute(total_income_aver_range_count$total_income_aver_range/12,sum_total_percentage,500)#家庭人均月收入累计区间分布
res

#家庭人均月收入占比累计图
plot(res$res,
  res$res_percentage,
  type="b",
  main="家庭人均月收入占比累计图",
  #sub="单位：元",
  xlab="月收入",
  ylab="累计占比")

#家庭人均年收入排名
income_rank=sqldf("select * from total_income_aver_range_count order by total_income_aver_range desc")
View(income_rank)

# barplot(income_rank$total_income_aver_range,
#         main="家庭人均年收入",
#         xlab="收入排名",
#         ylab="家庭人均年收入")

#家庭人均年收入区间分布图

# plot(
#   total_income_aver_range_count$count,
#   total_income_aver_range_count$total_income_aver_range,
#   type="b",
#   main="年收入分布",
#   #sub="单位：元",
#   xlab="人数",
#   ylab="年收入")

#有多少人年入<12000，即每个月收入<1000
less_12000=sqldf("select sum(count) from total_income_aver_range_count where total_income_aver_range<12000 ")
less_12000
total_count=sum(total_income_aver_range_count$count)
total_count
percent_less_12000=less_12000/total_count
percent_less_12000

#个人平均月收入
income_aver=sum(total_income_aver_range_count[c("total_income_aver_range")]*total_income_aver_range_count[c("count")])/total_count/12
income_aver

#个人月收入百分位数，不加权
quantile_p=c(0.1,0.2,0.3,.4,.5,.6,.7,.8,.9,.95,.99,.999)
y<-quantile(total_income_aver_range_count$total_income_aver_range/12,
            quantile_p,
            na.rm=TRUE)
y

#个人月收入百分位数，加权，加权才是对的
weighted_y<-wtd.quantile(total_income_aver_range_count$total_income_aver_range/12,
                         quantile_p,
                         na.rm=TRUE,
                         weight=total_income_aver_range_count$count)
weighted_quantile_p<-cbind(quantile_p, weighted_y)
weighted_quantile_p

#top1%、top10%、top20、top30的人占了多少财富
topN_c=c(0.01,0.05,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9)
res<-topN(topN_c,income_rank)
res<-data.frame(topN_c,res)
res

