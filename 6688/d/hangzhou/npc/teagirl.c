//by tlang
         
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("采茶少女", ({ "tea girl", "girl"}) );
	set("gender", "女性" );
	set("age", 16);
	set("long","这位笑嘻嘻地采着茶，一边还和同伴说笑。\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("rank_info/respect", "阿妹");
	set("vendor_goods", ([
		__DIR__"obj/tea1":20,
		__DIR__"obj/tea2":20,
	]));

	set_skill("dodge",50+random(40));
	set_skill("parry",50+random(40));
	set_skill("finger",50+random(40));
	set_skill("nianhua-zhi",60);
	map_skill("parry","nianhua-zhi");
	map_skill("finger","nianhua-zhi");
	
	setup();
	add_money("gold",1);
	carry_object("/d/hangzhou/npc/obj/girth")->wear();
}

void init()
{	
	add_action("do_vendor_list", "list");
}

