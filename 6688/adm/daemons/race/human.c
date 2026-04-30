// human.c

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
        ([      "action":               "$N挥拳攻击$n的$l",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N往$n的$l一抓",
                "damage_type":  "抓伤",
        ]),
        ([      "action":               "$N往$n的$l狠狠地踢了一脚",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N提起拳头往$n的$l捶去",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N对准$n的$l用力挥出一拳",
                "damage_type":  "瘀伤",
        ]),
});

void create()
{
        seteuid(getuid());
        set("unit", "位");
        set("gender", "男性");
        set("can_speak", 1);
        set("attitude", "peaceful");
        set("limbs", ({
                "头部", "颈部", "胸口", "後心", "左肩", "右肩", "左臂",
                "右臂", "左手", "右手", "腰间", "小腹", "左腿", "右腿",
                "左脚", "右脚"
        }) );
}

void setup(object ob)
{
        mapping my;
        int xism_age;
        int max_con;
        int tmp,i,j;
        string *h_gifts = ({"bln","kar","fav","lea","elo","msc","wil","vis"});
        // 2026-04-30: unused variable commented out
        // int maxage;

        my = ob->query_entire_dbase();

        ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
        
        if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;

        if( undefinedp(my["str"]) ) my["str"] = random(21) + 10;
        if( undefinedp(my["cor"]) ) my["cor"] = random(21) + 10;
        if( undefinedp(my["int"]) ) my["int"] = random(21) + 10;
        if( undefinedp(my["spi"]) ) my["spi"] = random(21) + 10;
        if( undefinedp(my["cps"]) ) my["cps"] = random(21) + 10;
        if( undefinedp(my["per"]) ) my["per"] = random(21) + 10;
        if( undefinedp(my["con"]) ) my["con"] = random(21) + 10;
        if( undefinedp(my["dex"]) ) my["dex"] = random(21) + 10;

        //生成隐含天赋
        j = sizeof(h_gifts);
        for(i=0;i<j;i++)
                if( undefinedp(my[h_gifts[i]]) ) my[h_gifts[i]] = random(21) + 10;

        //我们在attribute里面已经考虑到功夫的用处了。           
/*
        if( userp(ob) && ((tmp = ob->query_skill("buddhism", 1)) > 100) ) {
                tmp = (tmp - 100) / 10;
                ob->set("gift_imp/cps",tmp);
        }       
        if( userp(ob) && ((tmp = ob->query_skill("taoism", 1)) > 100) ) {
                tmp = (tmp - 100) / 10;
                ob->set("gift_imp/spi",tmp);
        }       
        if( userp(ob) && ((tmp = ob->query_skill("spells", 1)) > 100) ) {
                tmp = (tmp - 100) / 10;
                ob->set("gift_imp/msc",tmp);
        }                            
        if( userp(ob) && ((tmp = ob->query_skill("literate", 1)) > 20) ) {
                tmp = (tmp - 100) / 20;
                ob->set("gift_imp/int",tmp);
        }       
*/      
        
        if( userp(ob) || undefinedp(my["max_sen"]) ) {
                if( my["age"] <= 14 ) my["max_sen"] = 100;
                else if( my["age"] <= 20 ) my["max_sen"]=100+(10+ob->query("msc"))*(my["age"]-14);
                else if ( my["age"] <= 80) my["max_sen"] = 100+(10+ob->query("msc"))*6;
                else 
                        if( userp(ob) )
                                my["max_sen"] = 100 + 6 * (10+ob->query("msc")) - (my["age"] - 40) * 5;
                        else
                                my["max_sen"] = 100+(10+ob->query("msc"))*6;
                                
                if( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"] / 4;
                if( my["max_sen"] < 1 ) my["max_sen"] = 1;

        }

        if( userp(ob) || undefinedp(my["max_gin"]) ) {
                if( my["age"] <= 14 ) my["max_gin"] = 100;
                else if( my["age"] <= 20 ) my["max_gin"] = 100 + (my["age"] - 14) * (10+ob->query("spi"));
                else if( my["age"] <= 80 ) my["max_gin"] = 100 + 6 * (10+ob->query("spi"));
                else 
                        if( userp(ob) )         
                                my["max_gin"] = 100 + 6 * (10+ob->query("spi")) - (my["age"] - 40) * 5;
                        else
                                my["max_gin"] = 100 + 6 * (10+ob->query("spi"));

                if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] / 4;
                if( my["max_gin"] < 1 ) my["max_gin"] = 1;
                
                // 经验不能为负
                if (my["combat_exp"] < 0) 
                        my["combat_exp"] = 1;

                // 有关根骨的bug 
                max_con = ob->query_skill("force",1) / 4;
                if ( ob->query("luohan_winner") )
                     max_con += 2;
                if (max_con  < 30 ) max_con =  30;
                if ( my["con"] > 30 && my["con"] > max_con )
                      my["con"] = max_con;
                // 道家保神：
                if(my["age"] > 60 && (int)ob->query_skill("taoism", 1) >= 120)
                {
                // 关于道家年龄过大涨神的bug     yeung 01/28/99
                        if( my["age"] < 100)
                                my["max_sen"] += ((my["age"] - 60) * 5)/2;
                }
                // 佛家养神：３０岁前补神，３０岁后长神
                if((xism_age=(int)ob->query_skill("buddhism", 1)) > 80)
                {
                        int hunyuan,linji;

                        if (xism_age > 250) xism_age = 250;
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        hunyuan=(int)ob->query_skill("hunyuan-yiqi", 1);
                        linji=(int)ob->query_skill("linji-zhuang", 1);
                        if (hunyuan > 250) hunyuan = 250;
                        if (linji > 250) linji = 250;
                        if (xism_age > 0)
                                my["max_sen"] += (xism_age *(
                                        (hunyuan >= linji ? hunyuan : linji)/10))/4;
                }

// yeung 
//年龄的增长会降容貌，但是驻颜丹会减缓这种影响
                if( undefinedp(my["org_per"]) || my["org_per"]<my["per"] ) my["org_per"] = my["per"];
                if( my["org_per"] >= 70 ) my["org_per"] = 70;
                
                if( my["gender"] == "女性" && my["age"] > 70 ) //改为女性70岁开始韶华逝去
                {
                        my["per"] = my["org_per"]-((((my["age"]-35)/2 - my["吃驻颜丹"])>0)?((my["age"]-35)/2 - my["吃驻颜丹"]):0); // 2 年减一点魅力
                        if( my["org_per"] > 25 && my["per"] < 15 ) my["per"] = 15;  //原来的美丽的也不会太丑                        
                        if( my["per"] < 5 ) my["per"] = 5;                                                      
                }
                else  //男人老得比较慢 :)
                if( my["age"] > 80 )
                {
                        my["per"] = my["org_per"]-(my["age"]-45)/2; // 3 年减一点魅力
                        if( my["org_per"] > 25 && my["per"] < 15 ) my["per"] = 15;  //原来的美丽的也不会太丑                        
                        if( my["per"] < 5 ) my["per"] = 5;                                                      
                }
// yeung
// player天赋有上限
                if( my["str"] > 100 && !ob->query_temp("pfm/shaolin_jingang")) my["str"] = 100; //force <= 230,str <= 59
                if( ob->query_skill("banruo",1) < 100 && my["str"]>50 )
                        my["str"] = 50;

                if( my["cor"] > 50 ) my["cor"] = 50; 
                if( my["int"] > 100 ) my["int"] = 100; //literate can to 250                              
                if( my["spi"] > 50 ) my["spi"] = 50;
                if( my["cps"] > 50 ) my["cps"] = 50;
                if( my["per"] > 70 ) my["per"] = 70; // stormdance <= 200
                if( my["con"] > 50 ) my["con"] = 50;
                if( my["kar"] > 50 ) my["kar"] = 50;
        }

        if( userp(ob) || undefinedp(my["max_kee"]) ) {
                if( my["age"] <= 14 ) my["max_kee"] = 100;
                else if( my["age"] <= 20 ) my["max_kee"] = 100 + (my["age"] - 14) * (ob->query("con")*2);
                else if( my["age"] <= 80 ) my["max_kee"] = 100 + 6 * (ob->query("con")*2);
                else                            
                        if( userp(ob) )         
                                my["max_kee"] = 100 + 6 * (my["con"]*2) - (my["age"] - 40) * 10;
                        else
                                my["max_kee"] = 100 + 6 * (ob->query("con")*2);                         

                if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] / 4;
                
                if( my["max_kee"] < 1 ) my["max_kee"] = 1;

                //if( my["potential"] - my["learned_points"] > 500 && my["combat_exp"]<500000)
                        //my["potential"] = my["learned_points"] + 500;

                // 佛家保气：
                if(my["age"] > 60 && (int)ob->query_skill("buddhism", 1) >= 120)
                {
                // 关于佛家年龄过大涨气的bug     yeung 01/28/99
                        if( my["age"] < 100)
                                my["max_kee"] += ((my["age"] - 60) * 5)/2;
                }

                // 道家练气：３０岁前补气，３０岁后长气, 按菲波那契数列涨气
                if((xism_age=(int)ob->query_skill("taoism", 1)) > 39)
                {
                        int taiji,xiantian,lev;

                        if (xism_age > 250) xism_age = 250;
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        taiji=(int)ob->query_skill("taiji-shengong",1);
                        xiantian=(int)ob->query_skill("xiantian-gong", 1);
                        if (taiji > 250) taiji = 250;
                        if (xiantian > 250) xiantian = 250;
                        lev = taiji>xiantian?taiji:xiantian;
                        lev /= 11;
                        if (xism_age > 0)
                                while(lev>0)
                                {
                                        my["max_kee"] += (xism_age * 
                                                GLOBAL_D->query_fbnq(lev) /50 /95 );
                                        lev --;
                                }
                }
        }


        if( !ob->query_temp("apply/armor") )
                ob->set_temp("apply/armor", 20);
        //茅山派的气由于常年修习咒术,相对法力来说不重视气的修炼
        if( userp(ob) && ob->query("family/family_name") == "茅山派" && my["age"] < 100 && (ob->query_skill("necromancy",1)>100) )
        {
                my["max_kee"] = 100;
        }


        ob->set_default_object(__FILE__);

        // here may have negative weight
        if(my["str"]<12) my["str"]=12;

        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
        
        // 决定寿命
        if( userp(ob) )
        {
                my["max_age"] = 60 + 5 * my["con"] + (ob->query_skill("force",1)-100)/10 + 
                        (ob->query_skill("taoism",1)-100)/10 - my["died_times"];
        }
        
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

