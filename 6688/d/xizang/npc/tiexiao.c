// /d/xizang/npc/tiexiao.c
// 铁笑
//
// by mscat

#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

string ask_me();
string ask_me1();
string ask_me2();

void create()
{
	set_name("铁笑", ({ "tie xiao", "xiao", "tie" }) );
	set("gender", "男性");
	set("age", 24);
	set("long", @LONG
    铁笑本是中原侠客盟中的一等高手,在一次任务中身负重伤,与爱侣小梅失散
伤愈之后,他回到最初遇见小梅的雪梅谷,她却没有回来.小梅的父亲,雪山飞侠蓝
岚恨他不能保护女儿,把他赶出谷外.但他仍不死心,坚信小梅一定还活着,并且会
回到他身边,因此就近在拉萨城开了这家迎梅客栈,希望她能找回到这里.
LONG
            );
	set("attitude", "peaceful");

	set("str", 22);
	set("int", 30);
	set("cor", 35);
        set("per", 30);
	set("spi", 29);

	set("force", 8000);
	set("max_force", 4000);
	set("force_factor", 40);

	set("combat_exp", 5000000);
	set("score", 10000);
	set("env/wimpy", 50);
	
	set("inquiry", ([
		"学画" : (: ask_me1 :),
		"宝藏" : "宝藏倒是没有,不过有些奇怪的石头,可以拿来作雕刻",
		"卜鹰" : "那家伙是条汉子,就是为人比较古怪.",
		"小梅" : (: ask_me :),
		"买画" : (: ask_me2 :)
	]));

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
                (: exert_function, "recover" :),
	}) );

        set_skill("unarmed", 200);
        set_skill("force", 250);
	set_skill("parry", 250);
        set_skill("dodge", 250);
        set_skill("sword", 250);
	set_skill("perception", 150);
        set_skill("sevencolor", 250);
        set_skill("drawing", 250);
	set_skill("music", 200);
	set_skill("dancing", 220);
        set_skill("move", 250);
        set_skill("literate", 190);
        set_skill("feixue-quan", 220);
        set_skill("yaksword", 250);
//        set_skill("sword", "yaksword");
//        set_skill("parry", "yaksword");
        map_skill("unarmed", "feixue-quan");
        map_skill("force", "sevencolor");
        map_skill("dodge", "dancing");
	map_skill("move", "dancing");
        map_skill("parry", "yaksword");
        map_skill("sword", "yaksword");
      
	create_family("侠客盟", 7, "剑手");
	set("class", "legend");

	setup();
        carry_object(OBJ_DIR"cloth")->wear();
      carry_object(OBJ_DIR"weapon/gangjian")->wield();
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/xiaomei") ){
		command("shake");
                say("铁笑说道:我没什么可以教给你的啦!\n");
                return 0;
        }
        return 0;
}

string ask_me()
{
	if(this_player()->query("marks/xiaomei")) {
		return "多谢你帮我找到小梅,请代我向她问好.\n";
	}
	return "你能帮我找到她吗?.\n";
}

string ask_me1()
{
	if(this_player()->query("marks/xiaomei")) {
		return "其实我的画技也不能算很好,大家一起研究吧.\n";
	}
	return "找不到小梅,哪里有心思画画儿,你就别来烦我了.\n";
}

string ask_me2()
{
	if(this_player()->query("marks/xiaomei")) {
		return "小梅的画像我可舍不得卖.\n";
	}
	remove_action("do_answer", "answer");
	add_action("do_answer", "answer");
	return "我的画不卖,但是如果你答应帮我找到画上的女孩子,可以送你一幅\n"+
		"(answer yes/no)\n";
}

int do_answer(string arg)
{
	object ob, pic;
	if (!arg || ((arg !="yes") && (arg !="YES")) ){
	command("sigh");
	command("say 既然你不愿意,那就算了吧...");
	return 1;
	}
	ob=this_player();
	command("thank "+ ob->query("id"));
	command("say 拜托你了!");
	pic=new(__DIR__"obj/mei_pic");
	pic->move(ob);
	return 1;
}

int accept_fight(object me)
{
	object ob;
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon") ){
		if(!ob=present("jian", this_object())) {
			ob=new(OBJ_DIR"weapon/gangjian");
			ob->move(this_object()); 
		}
		ob->wield();
		command("say 既然这位"+RANK_D->query_respect(me) +
			"用兵刃,在下空手接招未免不敬.");
		return 1;
	}
	command("say 进招吧!");
	return 1;
}
