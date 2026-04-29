// /d/xizang/class/bad/npc/yak.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("侠客", ({ "yak", "xia ke", "ke" }));
	set("title", HBWHT+BLK+"百战剑狂"+NOR);
	set("gender", "女性" );
	set("age", 26);
	set("str", 30);
	set("cor", 29);
	set("cps", 30);
	set("per", 29);
	set("long", @TEXT
她就是人称"百战剑狂"的侠客.一般人不相信她是女的,更加不相信她的厨艺
居然不坏.恶人谷里,或者只有她的铺子还比较安全, 因为她除了斗剑没别的
爱好,而死人当然不能和她斗剑
TEXT
);
	set("combat_exp", 6400000);
	set("attitude", "heroism");
	set("kee", 3000);
	set("max_kee", 3000);
	set("gin", 3000);
	set("max_gin", 3000);
	set("sen", 3000);
	set("max_sen", 3000);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("dodge", 180);
	set_skill("sword", 600);
	set_skill("move", 180);
	set_skill("fonxansword", 200);
	set_skill("fonxanforce", 200);
	set_skill("chaos-steps", 200);
	set_skill("liuh-ken", 210);

	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "chaos-steps");
	map_skill("unarmed", "liuh-ken");
	map_skill("force", "fonxanforce");
//add some other skill
//add inquiry for accept fight
	set("vendor_goods", ([
		"酒"	: __DIR__"obj/wine1",
		"烈酒"	: __DIR__"obj/wine2",
		"小菜"	: __DIR__"obj/cai1",
		"咸菜"	: __DIR__"obj/cai2",
		"泡菜"	: __DIR__"obj/cai3",
		"炒菜"	: __DIR__"obj/cai4",
		"面条"	: __DIR__"obj/noodle",
		"米饭"	: __DIR__"obj/rice",
		"包子"	: __DIR__"obj/dumpling",
		"馒头"	: __DIR__"obj/mantou",
	]));
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/sword")->wield();
	carry_object(OBJ_DIR"weapon/dagger")->wield();
}
