//NPC:/d/suzhou/npc/yanqi.c
//by tlang
//98.2
       
#include <ansi.h>
inherit NPC;
string ask_for_hubiao();

void create()
{
        set_name(MAG"燕七"NOR, ({"yan qi", "yanqi" }));
	set("title", HIW"镖局长老"NOR);
	set("long", @LONG
他是镖局的镖局四大长老之一的燕七，年纪虽然不大，武功却是不同凡响。连
老长老龙五都未必是她的对手，尤其擅长轻功。
LONG
	);

	set("gender", "女性");
	set("attitude", "friendly");
	
	set("age", 20);
	set("shen_type", 100);
	set("str", 20);
	set("int", 35);
	set("con", 30);
	set("dex", 25);
	set("per", 35);
	set("max_kee", 800);
	set("max_gin", 300);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("combat_exp", 500000);
	set("score", 100000);
	set("apply/attack",  60);
	set("apply/defense", 60);

	set_skill("force", 100);
	set_skill("finger",100);
	set_skill("dodge", 120);
	set_skill("parry", 100);
	set_skill("nianhua-zhi",100);
	set_skill("xiaoyaoyou",120);
	set_skill("hunyuan-yiqi", 100);
       
        map_skill("finger", "nianhua-zhi");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "xiaoyaoyou");

	map_skill("parry", "nianhua-zhi");

        prepare_skill("finger", "nianhua-zhi");

	set("count",1);	
 	set("inquiry", ([
		"护镖" : (: ask_for_hubiao :),
		"hubiao" : (: ask_for_hubiao :),
	]));

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("gold", 3);
}  

void init()
{
	add_action("do_want","want");
}

string ask_for_hubiao()
{
	object me;
	me = this_player();
	
	if( me->query("class")=="guard" )
	{
		if( me->query("sender") )
        		return RED"你还没有完成，怎么又来了?\n"NOR;        
       		if(query("count") < 1)
                	return "抱歉，你来晚了，这次的镖已经有人护送了，等下次吧。\n";

                add("count", -1);

                me->set_temp("pending/hubiao", 1);
                        return "你想护镖，这是好事，但路上危险，你可愿意(want)？\n";
        }  else {
                return "你没有加入我们镖局，不能护镖。\n";
        }
}

int do_want()
{
	object me,ob1,ob2,ob;
	me = this_player();
	
	if(!me->query_temp("pending/hubiao") )
		return notify_fail("你想干啥哩？\n");
	else 
	{
	if(me->query("done3") )
        	return notify_fail("你完成过了，不用再去了。\n"NOR);        
       	tell_object(me,"这是一架相机，你把它送到杭州宝珠山庄，交给朱八太爷。\n"
	"记住路上小心应付，有盗贼来抢，但要自己应付，否则没有好处。也不用回\n"
	"来报告了，只要你把盗贼杀死并把东西送给朱八爷，这任务你就完成了。\n");
	me->set("sender", 1);
	me->delete("pending/hubiao");
	ob=new("/class/guard/npc/obj/camera");
	ob->move(me);
	ob1=new("/d/suzhou/npc/daozei.c");
	ob2=new("/d/suzhou/npc/daozei.c");
	ob1->move("/d/suzhou/hye");
	ob2->move("/d/quanzhou/qzroad3");
		return 1;      
        }  
	return 1;
}

