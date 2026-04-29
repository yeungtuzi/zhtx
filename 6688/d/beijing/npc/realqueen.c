//realqueen.c太后
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"太后"NOR, ({ "qing queen","queen"}) );
	set("gender", "女性" );
	set("age", 45);
	set("long", "太后姓博尔济吉特，因为长久不见阳光，形容憔悴，面无血色。\n");
	set("shen_type", 1);
	set("str", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
	setup();
	carry_object(__DIR__"obj/queencloth")->wear();
}
void init()
{
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
}

void greeting(object who)
{	object ob;
	ob=new("/obj/money/thousand-cash");
	ob->move(this_object());
	if(who->query_temp("savequeen"))
	 {
	who->set_temp("savequeen",0);
	message_vision("太后向$N道谢道：“谢谢你救了我，这里是一点珠宝，你拿去吧!”\n",who);
	command( "give "+who->query("id")+" thousand-cash");
	}
	return;
}