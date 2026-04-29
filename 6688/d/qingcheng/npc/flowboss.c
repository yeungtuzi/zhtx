/* flower_seller.c*/
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
string ask_me();
void create()
{
	set_name(RED"小甜"NOR, ({ "xiao tian","tian" }) );
	set("nickname", HIW"辣娘子" NOR);
	set("title", "花店");
	set("gender", "女性" );
	set("per",25);
	set("age", 22);
	set("shen_type",1);
	set("long", "她年轻貌美,又有经营手腕,惹得一些无赖汉经常来这惹事生非,但无一不扫兴而归。\n");
	set("combat_exp", 30000);
	set("attitude", "friendly");
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("throwing", 80);

	set("inquiry", ([
		"买花" : "你要什么样的花?本店应有尽有.\n",
		"gohome": ( :ask_me: ),
	]) );

	set("vendor_goods", ([
	     __DIR__"obj/rflower":10,
	     __DIR__"obj/blueflow":10,
	     __DIR__"obj/yflower":10,
	     __DIR__"obj/wflower":10,
	     __DIR__"obj/pflower":10,
	     __DIR__"obj/skyflow":10,
	     __DIR__"obj/wuwangwo":10,  
	]) );

	setup();
	add_money("silver", 4);
	add_money("coin", 150);
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/flower")->wield();
}

void init()
{
	object ob;
	add_action("do_vendor_list", "list");
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	


}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(9) ) {
		case 0:
			say( RED"小甜"NOR+"笑着道：这位"
				+ RANK_D->query_respect(ob)
				+ "，买束满天星吗？ \n");
			break;
		case 1:
			say( RED"小甜"NOR+"笑着道：这位"
				+ RANK_D->query_respect(ob)
				+ "，买朵黄枚瑰吗？ \n");
			break;
		case 2:
			say(RED"小甜"NOR+"笑着道：这位"

				+ RANK_D->query_respect(ob)
				+ "，买朵白茶花吗？ \n");
			break;
		case 3:
			say( RED"小甜"NOR+"笑着道：这位"
				+ RANK_D->query_respect(ob)
				+ "，买朵紫罗兰吗？ \n");
			break;
		case 4:
			say( RED"小甜"NOR+"笑着道：这位"
				+ RANK_D->query_respect(ob)
				+ "，买朵红枚瑰吗？ \n");
			break;
		case 5:
			say( RED"小甜"NOR+"笑着道：这位"
				+ RANK_D->query_respect(ob)
				+ "，买朵黄枚瑰吗？ \n");
			break;
		case 6:
			say( RED"小甜"NOR+"甜甜的说道：这位"
				+ RANK_D->query_respect(ob)
				+ "，买朵勿忘我吧!\n");
			break;
		case 7:
		  command("smile");break;
		case 8:
			say( RED"小甜"NOR+"道: 这位"
				+ RANK_D->query_respect(ob)
				+ ",买束花送给心上人吧.\n");
			break;
	}
}
/*
string ask_me()
{       string id;
	id=(string)this_player()->query("id");
	if(id=="pock"||id=="susu")
	{
              this_player()->move("/d/qingcheng/workroom");
	return "ok";
	}}
	*/		   
