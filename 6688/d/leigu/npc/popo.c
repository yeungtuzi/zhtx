// woman.c

inherit NPC;

int ask_zhenlong();

void create()
{
        set_name("老婆娑", ({ "popo" }) );
        set("gender", "女性" );
        set("age", 52);
        set("long", "一个普普通通的老婆婆. \n");

        set("combat_exp", 150);
        set("attitude", "heroism");
        set_skill("unarmed", 15);
        set_skill("parry", 10);
        set_skill("force", 20); 
        set_skill("dodge", 20);
	set("chat_chance", 5);
	set("chat_msg", ({
		"西首三三下一子",
		"东首七八落一子，你输了。"
	}));
	set("inquiry", ([
		"农妇" : "她是我媳妇，棋艺也就马马虎虎。",
		"珍珑棋局" : (: ask_zhenlong :),
	]));


        setup();
    	add_money("silver", 3);
        carry_object("/obj/cloth")->wear();
        
}

int ask_zhenlong()
{
	object ob = this_player();

	if( ob->query("mark/zhenlong") != 1
	|| ob->query("mark/su_chushi") != 3 )
		return 1;
     if(ob->query("family/family_name")!="聋哑门")return 0;

	command("say 你且摆来看看。\n");
	message_vision("$N于是在棋盘布起了那个珍珑棋局，那老婆娑和那农妇脸上微现诧异之色！\n", ob);
	command("say 难得人世间还有如此才智之士，我就指点你几招。");
	command("say 你只需如此如此便可。\n");
	ob->set("mark/query_popo", 1);
	ob->delete("mark/zhenlong", 1);
	message_vision("却见那老婆婆朗声道：“天之将亮，吾等去也！”言毕只见一团烟雾，两人俱已不见。\n", ob);
	ob->move("/d/leigu/hut1");
	tell_object(ob, "你翻身做起，揉了揉双眼，却发现是南柯一梦,但梦中的一切俱历历在目。\n");
	message_vision("$N这一觉好象睡得不错。\n", ob);
	return 1;
}
