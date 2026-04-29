// /d/xizang/npc/xiaoni.c

inherit NPC;
string ask_me();

void create()
{
        set_name("小妮", ({ "xiaoni", "kid" }) );
        set("gender", "女性" );

        set("age", 13);
        set("long", @LONG
小妮和小宝是孪生姐弟,不过她可不象小宝那么淘气,她正在帮妈妈做饭.
LONG
);
        set("combat_exp", 350);
        set("per", 25);
        set("inquiry", ([
               "宝藏": "真的有宝藏就好了.\n",
           "昆仑之墟": "昆仑之墟是诸神居住的地方.\n",
	     "采石场": "我爸就在那里工作,我要帮妈咪做好饭给他送去.\n",
	       "送饭": (: ask_me :),
	       "帮忙": (: ask_me :)
        ]) );
        set("attitude", "friendly");
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}

string ask_me()
{
	object me;
	me=this_player();
	if(me->query("marks/大雄")) return "谢谢你\n";
	if(me->query("marks/小妮")) return "快去吧,谢谢你了\n";
	add_action("do_answer", "answer");
	return "我要去送饭,但是...我怕狗...你能帮我去吗?\n"+
		"answer(yes/no)\n";
}

int do_answer(string arg)
{
	object me, ob;
	me=this_player();
	if(me->query("marks/小妮")) 
		return notify_fail("你已经答应过小妮帮她送饭了.\n");
	if (!arg || arg!="yes")
		say("小妮失望地说: 你不肯帮忙,那就算了.\n");
		return 1;
	ob=new(__DIR__"obj/ration");
	ob->move(me);
	message_vision("小妮给$N一包干粮.\n");
	say("小妮说: 谢谢你了.\n");
	me->set("marks/小妮", 1);
	return 1;
}
