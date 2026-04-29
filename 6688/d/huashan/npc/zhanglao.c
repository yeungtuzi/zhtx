//xiao-daoshi.c
inherit __DIR__"jian_npc.c";
#include <ansi.h>

string ask_me_1();
string ask_me_2();
string ask_me_3();

void create()
{
       set_name("长老", ({ "zhang lao", "zhanglao","taoist" }) );
	   set("title","执奉香火");
	   set("long",
@LONG
这是一位白发苍苍的老道士，他在这座庙里面已经呆了很多年了，大概有
五六十个年头了吧。他满脸都是皱纹，身材短小，好象枯干的树干一样，两
只眼睛很浑浊，但是在不经意之间却总会闪烁着几点精光。

LONG);
       set("combat_exp",random(100)*10000+300000);
       set("str",50);
       set("int",50);
       set("cor",50);
       set("cps",50);
       set("age",70);
       set("gender","男性");

       create_family("华山派剑宗",19,"弟子");
       set_skill("sword",random(200)+50);
       set_skill("huashan-jianfa",random(200)+50);
       set_skill("wind-sword",250);
       set_skill("huashan-shenfa",random(200)+50);
       set_skill("poyu-quan",random(200)+50);
       set_skill("dodge",random(200)+50);
       set_skill("parry",random(200)+50);
       set_skill("cuff",random(200)+50);
       set_skill("dugu-jiujian",50);
       set_skill("zong-jue",50);
       set("force_factor",150);
       set("max_force",3000);
       set("force",5000);
       set("max_kee",2000);
       set("kee",2000);
       set("max_sen",2000);
       set("sen",2000);
       set("max_gin",2000);
       set("gin",2000);
       set("max_mana",2000);
       set("mana",2000);
       set("atman",2000);
       set("max_atman",2000);
       set("inquiry", ([
                "秘密" :	 (: ask_me_1 :),
                "学艺" :         (: ask_me_2 :),
                "师叔祖" :	 (: ask_me_3 :),
        ]));

       map_skill("dodge","huashan-shenfa");
       map_skill("sword","wind-sword");
       map_skill("cuff","poyu-quan");
       map_skill("parry","wind-sword");
       prepare_skill("cuff","poyu-quan");

       setup();
       carry_object(OBJ_DIR+"weapon/sword.c")->wield();
       carry_object(__DIR__"obj/taijirobe.c")->wear();
       add_money("silver",random(50)+50);
}

int killed_enemy(object ob)
{
    if(userp(ob))
       command("sigh");
    return 1;
}

int accept_object(object me, object what)
{                                 
     if(me->query("mark/secret/kill_fox"))
	    return 0;
   
	if(me->query("mark/secret_fail"))
		return 0;

    if( !me->query("mark/secret/1_ask_zhanglao") ) return 0;
    if(base_name(what)!="/u/e/emote/huashan/npc/obj/khbd")
		return 0;
	if(what->query_name()!="「葵花宝典残本」")
	 	return 0;
	command("smile");
	command("thank "+me->query("id"));
	command("admire "+me->query("id"));
	me->set("mark/secret/2_give_zhanglao",1);
        return 1;                   
}



string ask_me_1()
{
	int i;
	object *inv=all_inventory(this_object());

	if(this_player()->query("mark/secret/kill_fox"))
	    return "哼！\n";
   
	if(this_player()->query("mark/secret_fail"))
		return "哼，不长进的东西，又来问我啊。\n";

	if(this_player()->query("family/family_name")!="华山派剑宗")
		 return "这里哪里有什么秘密呢？\n";
	for(i=0;i<sizeof(inv);i++)
	{
	  if(inv[i]->query("id")==this_player()->query("id")
	  ||   inv[i]->query("id")=="zhang lao")
	      continue;
		else
		{
			if(living(inv[i]))
			{
				this_player()->set("mark/ask_zhanglao",time()+900);
				return "这里哪有什么秘密呢？\n";
			}
			
		}
	}
	if(time()<this_player()->query("mark/ask_zhanglao"))
		return "呵呵，你又来问了，老朽这里可没什么秘密。\n";
	
	if(this_player()->query("mark/secret/1_ask_zhanglao")
	&& this_player()->query("mark/secret/2_give_zhanglao"))
	{
		    command("tell "+this_player()->query("id")+" 谢了，你以后有什么事情可以尽管向我问，我能够解答的尽量帮忙");
			this_player()->set("mark/secret/3_can_ask_zhanglao",1);
			return "呵呵，看起来这位"+RANK_D->query_respect(this_player())+"气色不错啊\n";
	}
	
	if(this_player()->query("hatred/华山派气宗")<20000 || random(100)>5)
	{
			this_player()->set("mark/ask_zhanglao",time()+900);
			return "这里哪有什么秘密呢？\n";
	}
    if(!this_player()->query("mark/secret/1_ask_zhanglao"))
	{
			command("tell "+this_player()->query("id")+" 赶紧去帮贫道办妥这件事情，贫道必定重重有谢。");
			this_player()->set("mark/secret/1_ask_zhanglao",1);
			return "呵呵，今儿天气真不错啊。\n";
	}
	
}

string ask_me_2()
{
	object ppl=this_player();
	if(ppl->query("mark/secret/kill_fox"))
	    return "哼！\n";
   
	if(ppl->query("mark/secret_fail"))
		return "哼，不长进的东西，又来问我啊。\n";

	if(!ppl->query("mark/secret/3_can_ask_zhanglao"))
	{
		this_player()->set("mark/ask_zhanglao",time()+900);
		command("faint");
		return "这个啊，呵呵，还要等等。\n";
	}
	ppl->set("mark/secret/4_can_learn",1);
	return "既然承蒙不弃，看地起我这把老骨头，我就倾囊传授了。";
}
string ask_me_3()
{
	object ppl=this_player();
	object ob;

	if(ppl->query("mark/secret/kill_fox"))
	    return "哼！\n";
   
	if(ppl->query("mark/secret_fail"))
		return "哼，不长进的东西，又来问我啊。\n";

	if(!ppl->query("mark/secret/3_can_ask_zhanglao"))
	{
		this_player()->set("mark/ask_zhanglao",time()+900);
		command("faint");
		return "你瞎问什么呢？我怎么会知道你师叔祖在哪里啊？\n";
	}
	if(ppl->query_skill("zong-jue",1)<50)
	{
		return "你还是先跟我学着吧。\n";
	}
	if(ppl->query_skill("zong-jue",1)==50)
	{
		command("smile");
		command("say 你问你师叔祖啊，我也很长时间没看见过他了，不过他给我留了一封信，并且叫我帮他
留守在这里，负责看管他的剑，并且帮他物色佳弟子，既然你已学得我的剑术，现在也可以去找他了。");
        command("say 我把剑给你，你去玉女峰一带找找他吧，大概他会在那里，能不能找到他，就看你的
造化了。");
        ob = new(__DIR__"obj/fengsword.c");
		ppl->set("mark/autoload_fengsword",1);
		ob->move(ppl);
		ppl->set("mark/secret/5_lookforfeng",1);
		return "哈哈，贫道的重担总算解脱了。\n";
	}
	
}

int accept_learn(object me, string skill)
{
        if(me->query("mark/secret/kill_fox"))
	    return 0;
   
		if(me->query("mark/secret_fail"))
		return 0;

		if (skill=="dugu-jiujian" || skill=="zong-jue")
        {
                if (me->query("mark/secret/4_can_learn") )
                        return 1;
        }
        return 0;
}
