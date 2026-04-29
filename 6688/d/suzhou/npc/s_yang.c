// herbalist.c=>s_yang.c

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string heal_me(object me);

void create()
{
	set_name(YEL"杨三疯"NOR, ({ "yang sanfeng", "yang" }) );
	set("title", "天下第一恶条");
	set("gender", "男性" );
	set("age", 24);
	set("long",@LONG
		他是雪亭阵杨掌柜的儿子，但从小有些疯疯颠颠的，爱做坏
事情，被称为天下第一恶条。
LONG		
);
	set("combat_exp", 10000);
	set("attitude", "friendly");

	set("max_gin", 200);
	set("max_kee", 400);
	set("max_sen", 300);

	set("inquiry", ([
		"治伤": (: heal_me :),
		"疗伤": (: heal_me :),
		"开药": (: heal_me :),
	]) );
	set("vendor_goods", ([
		__DIR__"obj/ginseng" : 80,
		__DIR__"obj/ice_lotus" : 30,
		__DIR__"obj/agaric" : 60,
		"/obj/food/medicine" : 100,
	]) );

	set_skill("literate", 50);
	set_skill("dodge", 70);
	set_skill("unarmed", 80);

	setup();
	add_money("silver", 10);
	carry_object("/d/suzhou/npc/obj/qbcloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
}

string heal_me(object me)
{
	int ratio;

	ratio = (int)me->query("eff_kee") * 100 / (int)me->query("max_kee");
	if( ratio >= 100 )
		return "这位" + RANK_D->query_respect(me) + "，您看起来气色很好啊，不像有受伤的样子。";
	if( ratio >= 95 )
		return "哦....我看看....只是些皮肉小伤，您买包金创药回去敷敷就没事了。";
	
}
