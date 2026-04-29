// /d/xizang/npc/daxiong.c

inherit NPC;

string ask_me();

void create()
{
	set_name("大雄", ({ "daxiong", "xiong" }) );
	set("gender", "男性" );
	set("age", 36);
	set("long", @LONG
    大雄是汉族人,刚来到拉萨不久.
LONG
);
	set("combat_exp", 1500);
	set("str", 31);
	set("con", 30);
	set_skill("hammer", 80);
	set_skill("literate", 10);
	set("inquiry", ([
		"学藏文": (: ask_me :),
	]));
	setup();
	carry_object(OBJ_DIR"weapon/hammer")->wield();
	carry_object(OBJ_DIR"cloth")->wear();
	add_money("silver", 1);
}

string ask_me()
{
	object me, ob;
	me=this_player();
	if(me->query("race")=="藏族人") 
		return "我的藏文不好,还要向"+RANK_D->query_respect(me)+
			"多多请教.\n";
	if(!me->query("marks/小妮"))
		return "我现在很忙,以后再说吧.\n";
        if(me->query("marks/大雄"))
                return "我的藏文不好,教不了你更多了,你去找喇嘛们学吧.\n";
	if(!objectp(ob=present("ration", me)))
		return "我现在很忙,以后再说吧.\n";
	ob->move(this_object());
	message_vision("$N把小妮托付的干粮交给大雄.\n", me);
	me->set("marks/大雄", 1);
	return "正好,一边吃饭,一边教你认几个我刚学会的藏文字.\n";
}
