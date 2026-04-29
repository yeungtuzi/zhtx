// /d/xizang/class/bad/npc/littleyd.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("寒夜斩", ({ "littleyd", "han ye zhan", "zhan" }));
	set("title", HIM+"鬼诸葛"+NOR);
	set("gender", "男性" );
	set("age", 35);
	set("str", 24);
	set("cor", 24);
	set("cps", 25);
	set("int", 35);
	set("per", 22);
	set("long", @TEXT
他是茅山弟子,据说道行犹在掌门人林忌之上.昔年纵横江湖,专以诡计杀
人,号称"鬼诸葛",是个黑白两道人人头痛的家伙
TEXT
);
	set("combat_exp", 2300000);
	set("attitude", "heroism");
	set("force", 3000);
        set("max_force", 3000);
        set("mana", 2000);
        set("max_mana", 2000);
        set("atman", 2000);
        set("max_atman", 2000);
        set("force_factor", 50);
        set("mana_factor", 15);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("dodge", 180);
	set_skill("literate", 160);
        set_skill("magic", 160);
        set_skill("force", 225);
        set_skill("spells", 180);
        
        set_skill("taoism", 160);
        set_skill("necromancy", 199);
        set_skill("gouyee", 250);
        
        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        
        set_temp("apply/dodge",15);
        set_temp("apply/armor",15);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
}
