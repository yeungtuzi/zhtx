// wokou.c
// by Tang


#include <ansi.h>

inherit NPC;

string *first_name = ({ "龟田","武宫","小林","山本","田中","西条",
"上杉","丰臣","木下","桥本","竹下","酒井" });
string *name_words = ({ "太郎","次郎","三郎","四郎",
"秀季","英机","雷臧","康夫","原","健","刚造","三十七", });

int random_go();

void create()
{
        int i;

        string name, id;

        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "xiao riben" }) );

        set("title", HIR"小"+HIW"日本"NOR);
        set("gender", "男性" );
        set("shen_type", -1);
        set("age", 30+random(30));
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("long",
                "这是个脞得不能再脞的小日本，露着满嘴的黄牙，让人一看就觉得恶心。\n" );

        set("attitude", "aggressive");

        i=random(400)+30;

        set("combat_exp",i*i*i*2/10);

        set("eff_kee",500+(i-50)*5);
        set("max_kee",500+(i-50)*5);
        set("max_force",i*15);
        set("force",i*15);
        set("force_factor",i/2);
        set("food",1000);
        set("water",1000);

        set_skill("blade", i);
        set_skill("dodge", i);
        set_skill("unarmed", i);
        set_skill("parry", i);
        set_skill("force", i);

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",  200);

    set("chat_chance",50);
	set("chat_msg", ({
               (: random_go :)
        }) );
        set("bellicosity", 10000);
        set("kill_npc",0);
        
        setup();
        
        carry_object("/d/suzhou/npc/obj/wushidao")->wield();
        carry_object("/d/suzhou/npc/obj/cloth")->wear();
        //if (random(3) > 1 )carry_object("/u/m/masterall/obj/hbook");

}

void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
        object me, room1;
        if( !ob || !objectp(ob) ) return;
        me = this_object();
        room1 = environment(me);


        if(ob->query("id")=="xiao riben") return 0;
                command("say 你的，和我米西米西的干活去，不然就死拉死拉的有！\n");
                me->set_leader(ob);
				kill_ob(ob);
				if(!userp(ob))
                {
					if ( ( ob->query("combat_exp") > query("combat_exp") ) && random(100) > 50 )
					{
						message("system",HIR "\n【纵横天下】抗日英豪(KANG RI)："+ob->name()+HIR"哼了一声：弹丸小国的流寇，竟敢到我中原来撒野！！真是想死想疯了！\n"NOR,users() );
						ob->kill_ob(this_object());
					}
					else message("system",HIR "\n【纵横天下】抗日英豪(KANG RI)："+ob->name()+HIR"声嘶力竭的喊道，“诸位大侠快来救命啊，有倭寇当街行凶了！！”\n"NOR,users() );
                }
}


int killed_enemy(object ob)
{
     object riben= this_object();
     message("system",HIW "\n【纵横天下】抗日英豪(KANG RI)："+riben->name()+"邪恶的发出了一阵狞笑！\n"NOR,users() );
     add("kill_npc", 1);
     add_temp("apply/damage", 100);
     add_temp("apply/attack", 20);
     add("combat_exp", 500000);
     add("force", 5000);
}                 


void die()
{
        mapping victims;
        string *vic;
        int i,exp,pot,wlshw;
        object riben;
        object ob;


        ob = this_object()->query_temp("last_damage_from");
        riben = this_object();
		
		if (objectp(ob))
		{
			exp = random(4000) + ob->query("kar")*80;
			pot = random(2000) + ob->query("kar")*40;
                        wlshw = random(2);

                          if(riben->query("kill_npc")>3)
			  { 
					message_vision(HIR"\n$N阴笑道：“老子已经杀够本了，你爱怎么着就怎么着吧！”\n\n"NOR,this_object(),ob);
					message_vision(HIY"\n$n一想到$N的丧尽天良的恶行，不由得怒火上涌，冲上前去把$N剁成了烂泥！\n\n"NOR,this_object(),ob);
			  }
			  else
			  {
					ob->add("combat_exp",exp);
					ob->add("potential",pot);
					ob->add("wlshw", wlshw);
					message_vision(HIR"\n$N突然跪在地上，磕头如捣蒜，一个劲的求饶，\n$n眼眉一立，怒喝道，“堂堂华夏之邦，哪容得你这种恶徒来捣乱！下地狱去吧！”\n\n"NOR,this_object(),ob);
					message("system",HIC "\n【纵横天下】抗日英豪(KANG RI)："+ob->name()+"仗义行侠，终于将倭寇铲除一只，\n"+HIG"得到了"+chinese_number(exp)+"点经验、"+chinese_number(pot)+"点潜能、"+chinese_number(wlshw)+"点武林声望的奖励！！\n"NOR,users() );
			  }
		}
        ::die();

}

int random_go()
{
	mapping exits;
	string *dirs;
	if(is_fighting()) return 0;
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
}
