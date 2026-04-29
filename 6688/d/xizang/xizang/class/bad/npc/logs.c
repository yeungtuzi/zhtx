// /d/xizang/class/bad/npc/logs.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("流星雨", ({ "logs", "liuxing yu", "yu" }));
	set("title", HIM+"铁血变态"+NOR);
	set("gender", "男性" );
	set("age", 25);
	set("str", 33);
	set("cor", 33);
	set("cps", 23);
	set("int", 30);
	set("per", 26);
	set("long", @TEXT
他就是号称铁血变态的流星雨,喜好以各种刁钻手段折磨初入江湖的少年人,有
时连老江湖也被他修理得哭笑不得.他称之为"教练"别人适应险恶江湖.另外他
也喜欢找东洋武士挑战,曾经鼓动江湖同道远赴东瀛,可惜不胜刹羽而归, 后来
因为得罪人太多,才被迫躲进恶人谷.唐话和道可道都是他的密友.
TEXT
);
	set("combat_exp", 50000000);
	set("attitude", "heroism");
	set_skill("unarmed", 300);
	set_skill("parry", 300);
	set_skill("dodge", 280);
	set_skill("blade", 300);
	set("max_atman", 30000);
        set("atman", 30000);
        set("max_force", 3000);
        set("force", 6000);
	set("force_factor",150);
        set("max_mana", 30000);
        set("mana", 30000);
	set_skill("literate", 100);
	set_skill("meihua-shou", 200);
	set_skill("shortsong-blade", 230);
	set_skill("qidaoforce", 250);
        set_skill("fall-steps", 200);
	map_skill("unarmed", "meihua-shou");
	map_skill("blade", "shortsong-blade");
        map_skill("force", "qidaoforce");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");
	
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangdao")->wield();
	carry_object(OBJ_DIR"weapon/shield")->wear();
}
