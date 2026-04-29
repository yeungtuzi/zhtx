//modified by tlang for /cmds/std/look.c 
//this is for descripe a person's bellicosit for look.c

string *bel_msg_male1 = ({
        "脸上露出凛冽的杀机。",
        "昂着头，冷冷地让人不敢亲近。",        
});

string *bel_msg_male2 = ({
        "眉头紧锁，似乎有些心事。",        
        "闷闷不乐。",
});

string *bel_msg_male3 = ({
        "脸上露出灿烂的笑容。", 
        "脸上露出愉快的微笑。",
});

string *bel_msg_female1 = ({
        "冷冰冰地让人不敢亲近。",
        "粉脸中透出一些杀气。",   
});

string *bel_msg_female2 = ({
        "眉头轻蹙，似乎有些心事。",     
        "有些不大高兴。",
});

string *bel_msg_female3 = ({
        "在轻轻拨弄着衣带。",
        "愉快地笑着。",
//        "看上去天真无邪。",           
});

string *bel_msg_nomale1 = ({
        "似乎有什么心事。",
        "眼光到处搜索，不知道是在搜寻什么。",   
});

string *bel_msg_nomale2 = ({
        "轻声叹息，眼光中有种莫名的忧伤。",     
        "目光奇特，也不知道是中什么邪了。",
});

string *bel_msg_nomale3 = ({
        "露出一种莫名其妙的奇异表情。",
        "兴奋莫名，也不知道为什么。",
        "露出一种不正常的表情。",           
});

string bel_status_msg(int bellicosity,string gender)
{
        if ( gender == "男性" ) {
                if ( bellicosity>=500 )        
                return ( bel_msg_male1[random(sizeof(bel_msg_male1))]); 
                else if ( bellicosity>=100 )
                return ( bel_msg_male2[random(sizeof(bel_msg_male2))]); 
                else if ( bellicosity<100 )
                return ( bel_msg_male3[random(sizeof(bel_msg_male3))]); 
        }                                                        
        if ( gender == "女性" ) {
                if ( bellicosity>=500 )
                return ( bel_msg_female1[random(sizeof(bel_msg_female1))]); 
                else if ( bellicosity>=100 )
                        return ( bel_msg_female2[random(sizeof(bel_msg_female2))]);
                else if ( bellicosity<100 )
                return ( bel_msg_female3[random(sizeof(bel_msg_female3))]);
        }
       else {
                if ( bellicosity>=500 )
                return ( bel_msg_nomale1[random(sizeof(bel_msg_nomale1))]); 
                else if ( bellicosity>=100 )
                        return ( bel_msg_nomale2[random(sizeof(bel_msg_nomale2))]);
                else if ( bellicosity<100 )
                return ( bel_msg_nomale3[random(sizeof(bel_msg_nomale3))]);
        }
}

//this is for descripe a person's per.
string *per_msg_male01 = ({
        "相貌清秀，仪表不凡。" ,
        "活泼伶俐，讨人喜欢。" ,
});

string *per_msg_male02 = ({
        "相貌一般，五官还算端正。" ,
});

string *per_msg_male03 = ({
        "大耳招风，鼻孔向天，真是个好生丑陋的孩子。" ,
});

string *per_msg_male1 = ({
        "英俊潇洒,风度翩翩，气死潘安，羞死宋玉。" ,
        "相貌出众,面目俊朗，星目含情，剑眉露威。" ,
});

string *per_msg_male2 = ({
        "英俊潇洒,风度翩翩。",
        "相貌出众,面目俊朗。",
});
string *per_msg_male3 = ({
        "相貌平平，没什麽好看的。",
        "长得蔫蔫的，一副无精打采的模样。",
        "相貌凶恶，满脸横肉。",
});

string *per_msg_male11 = ({
        "精神矍铄，鹤发童颜。" ,
        "威风凛凛，英雄丝毫不减当年。" ,
});

string *per_msg_male12 = ({
        "毕竟已经是老人了，牙齿开始松动，说话也含糊不清。" ,
        "已经是风烛残年，再不复当年之勇了。",
});

string *per_msg_male13 = ({
        "皮肤如同风干的橘子皮一般，脸上到处是如刀刻之深的皱纹。" ,
});

string *per_msg_female01 = ({
        "虽然形容尚小，身量未足，却已是个十足的美人胎子。",
        "活泼可爱，娇俏喜人。",
});

string *per_msg_female02 = ({
        "相貌一般，五官还算端正。" ,
});

string *per_msg_female03 = ({
        "大耳招风，鼻孔向天，真是个好生丑陋的孩子。" ,
});

string *per_msg_female1 = ({
        "容色秀丽，风姿绰约，有一段说不出的风流体态。",
        "长发如云，肌肤胜雪，不知倾倒了多少英雄豪杰。 ",
        "俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。",
        "风情万种，楚楚动人，当真是我见犹怜。",
});
                
string *per_msg_female2 = ({
        "虽算不上绝世佳人，也颇有几份姿色。 ",
        "长得还不错，颇有几份姿色。  ",
});

string *per_msg_female3 = ({
        "的相貌嘛，马马虎虎了..." ,
        "面相丑恶，正是一个黄脸婆。 ",
});

string *per_msg_female11 = ({
        "驻颜有术，虽已半老，仍然端丽迷人，风采不减当年。" ,
        "仍然是风姿绰约，肤如凝脂，令人难以揣测真实年龄。" ,
});

string *per_msg_female12 = ({
        "容颜虽已随年华逝去，却看起来慈祥可亲。" ,
});

string *per_msg_female13 = ({
        "皮肤如同风干的橘子皮一般，脸上到处是如刀刻之深的皱纹。" ,
});
          
string *per_msg_nomale1 = ({
	"长发披肩，肌肤动人，也看不出是男是女。" ,
        "眉清目秀，有三分象宋玉，却有七分象飞燕。 ",
});
                
string *per_msg_nomale2 = ({
        "面目清秀，只是隐隐露出一中女儿的脂粉气。",
        "看上去也不知道长的怎样，但嘴角的笑却让男人和女人都有些心动。 ",
});

string *per_msg_nomale3 = ({
        "长得还可以，只是既没有男人的粗犷，又缺少女子的温柔。 ",
        "本来还有点粗犷美，但现在却有些扭捏作态，不男不女。",
});
          

string per_status_msg(int per, string gender,int age)
{          
        if ( gender == "男性" )
        {
                if ( per>=25 )
                {        
                	if( age < 18 )
	                	return ( per_msg_male01[random(sizeof(per_msg_male01))]); 
			if( age < 45 )	                		
	                	return ( per_msg_male1[random(sizeof(per_msg_male1))]); 			
	                else
	                	return ( per_msg_male11[random(sizeof(per_msg_male11))]); 	                
                }
                else if ( per>=15 )
                {        
                	if( age < 18 )
	                	return ( per_msg_male02[random(sizeof(per_msg_male02))]); 
			if( age < 45 )	                		
	                	return ( per_msg_male2[random(sizeof(per_msg_male2))]); 			
	                else
	                	return ( per_msg_male12[random(sizeof(per_msg_male12))]); 	                
                }
                else
                {        
                	if( age < 18 )
	                	return ( per_msg_male03[random(sizeof(per_msg_male03))]); 
			if( age < 45 )	                		
	                	return ( per_msg_male3[random(sizeof(per_msg_male3))]); 			
	                else
	                	return ( per_msg_male13[random(sizeof(per_msg_male13))]); 	                
                }
    	}                                                        
        if ( gender == "女性" )
        {
                if ( per>=25 )
                {        
                	if( age < 18 )
	                	return ( per_msg_female01[random(sizeof(per_msg_female01))]); 
			if( age < 45 )	                		
	                	return ( per_msg_female1[random(sizeof(per_msg_female1))]); 			
	                else
	                	return ( per_msg_female11[random(sizeof(per_msg_female11))]); 	                
                }
                else if ( per>=15 )
                {        
                	if( age < 18 )
	                	return ( per_msg_female02[random(sizeof(per_msg_female02))]); 
			if( age < 45 )	                		
	                	return ( per_msg_female2[random(sizeof(per_msg_female2))]); 			
	                else
	                	return ( per_msg_female12[random(sizeof(per_msg_female12))]); 	                
                }
                else
                {        
                	if( age < 18 )
	                	return ( per_msg_female03[random(sizeof(per_msg_female03))]); 
			if( age < 45 )	                		
	                	return ( per_msg_female3[random(sizeof(per_msg_female3))]); 			
	                else
	                	return ( per_msg_female13[random(sizeof(per_msg_female13))]); 	                
                }
    	}
	else
	{
                if ( per>=25 )        
                return ( per_msg_nomale1[random(sizeof(per_msg_nomale1))]); 
                else if ( per>=20 )
                return ( per_msg_nomale2[random(sizeof(per_msg_nomale2))]); 
                else if ( per<20 )
                return ( per_msg_nomale3[random(sizeof(per_msg_nomale3))]); 
    	}                                   
}


