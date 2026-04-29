// master.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(BLU"严北"NOR, ({ "yan bei", "yan", "bei" }) );
	set("title",RED"血剑"NOR);
	set("gender", "男性");
	set("age", 44);
	set("attitude", "aggressive");

        set("str", 40);
        set("int", 30);
        set("cps", 50);
        set("cor", 100);
 
        set("max_kee", 5000);
        set("max_gin", 3000);
        set("max_sen", 300);
        set("atman", 300);
        set("max_atman", 300);
        set("mana", 300);
        set("max_mana", 300);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 300);
        set("combat_exp", 15000000);
        set("score", 500000);
        set_temp("apply/armor",200);
        set_temp("apply/armor_vs_force",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",200);
        set_temp("apply/dodge",100);

        set_skill("force", 220);
        set_skill("taiji-shengong", 220);
        set_skill("move", 200);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("move", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");
        
        setup();
        carry_object(__DIR__"obj/bloodsword")->wield();
}