#include <ansi.h>

inherit NPC;

int do_bihua(string arg);
int checking(object me, object ob);

void create()
{
	set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
	set("title", "星宿派大师兄");
	set("long", @LONG
他就是摘星子，只三十多岁就做了星宿派的大师兄，功夫甚是了得。
他三缕长须，手摇折扇，神态甚是闲雅，已颇有星宿小怪的风范。
LONG);
	set("gender", "男性");
	set("age", 34);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 34);
	set("int", 20);
	set("per", 25);
	set("con", 26);
	
	set("max_kee", 1000);
	set("max_gin", 300);
	set("max_sen", 300);
	set("force", 1200);

	set("max_force", 1200);
	set("force_factor", 40);

	set("combat_exp", 400000);
	set("score", 30000);

	set("inquiry", ([
		"大师兄" : "本门规矩，武功高者为大，你想试试吗？(bihua)。",
	]));	

	set_skill("force", 100);
	set_skill("huagong-dafa", 70);
	set_skill("dodge", 90);
	set_skill("strike", 100);
	set_skill("xingxiu-duzhang", 40);
	set_skill("parry", 60);
	set_skill("literate", 80);
	set_skill("dugong", 80);
	set_skill("fushi-dugong", 80);

	map_skill("force", "huagong-dafa");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "xingxiu-duzhang");
	map_skill("dugong", "fushi-dugong");

	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/obj/cloth")->wear();
	add_money("gold", 2);
}

void init()
{
	add_action("do_bihua", "bihua");
	::init();
}

int do_bihua(string arg)
{
	object ob, me;

	ob = this_player();
	me = this_object();

	if( ob->query("family/family_name") != "星宿派" 
	|| ob->query("betrayer") )
		return 1;
	if( ob->query("mark/ding_chushi") )	return 1;
	
	if( me->query("title") != "星宿派大师兄" ){
		message_vision("$N神情沮丧，我早已不是什么大师兄了。\n", me);
		return 1;
	}

	if( me->query("kee") != me->query("max_kee") 
	|| me->query("gin") != me->query("max_gin") 
	|| me->query("sen") != me->query("max_sen")){ 
		command("say 我太累了，改日吧！");
		return 1;
	}

	if( me->is_fighting() || me->is_busy() ){
		command("say 没看我正忙着吗？！");			
		return 1;
	}

	message_vision(HIR"\n$N哼的一声冷笑！\n"NOR, me);	
	command("say 很好，你若胜了我，这大师兄的位子就是你的啦！");
	ob->set_temp("bihua_zhaixing", 1);
	me->kill_ob(ob);
	ob->fight_ob(me);
	call_out("checking", 1, me, ob);
	return 1;
}

int checking(object me, object ob)
{
	object *obs;
	int i;
	string ob_title;
	string *msg = ({
"$t神功盖世，普天之下，除了老仙，就数他第一了，凭你小小摘星子，也敢和他比拼？\n",
"其实$t功夫早就胜过你了，只是我们$t一向谦虚，才一直没向你要这个大师兄的位子！\n",
"摘星子你还不向$t跪地求饶，我们$t为人宽厚，或可饶你一命！\n",
"我早看出摘星子这厮心术不正，今天$t为本门清理门户，功不可没！\n",
"星宿$t，德配天地，威振四方，当世无比！\n",
});

	if( !present(ob, environment()) ){
		command("say 哼，就这点功夫也想抢大师兄的位子！");
		ob->delete_temp("bihua_zhaixing");
		return 1;
	}

	if( sizeof(me->query_enemy()) > 1 ){
		command("say 嘿嘿，看来想做大师兄的人还不少！\n");
		ob->delete_temp("bihua_zhaixing");
		return 1;
	}

	if( me->is_fighting() ){	
		call_out("checking", 2, me, ob);
		return 1;
	}
		
	if( !living(me) ){
		if( !ob->query_temp("bihua_zhaixing") )	return 1;
		ob->set("mark/ding_chushi", 1);
		ob->delete_temp("bihua_zhaixing");
		me->delete("title");
		if( ob->query("gender") == "女性" ){
			message_vision(HIG"$N夺得了星宿派大师姐的称号。\n"NOR, ob);
			ob->set("title", "星宿派大师姐");
			ob_title = "大师姐";
		}
		else{
			message_vision(HIG"$N夺得了星宿派大师兄的称号。\n"NOR, ob);
			ob->set("title", "星宿派大师兄");
			ob_title = "大师兄";
		}
		tell_object(ob, "\n四周响起一片阿谀奉承之声。\n\n");
		for(i=0; i<sizeof(msg); i++){
			message_vision(MAG+replace_string(msg[i], "$t", ob_title)+NOR, ob);
		}
		return 1;
	}

	return 1;
}
