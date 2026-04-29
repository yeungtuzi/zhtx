// /d/xizang/class/bad/npc/llkkjj.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("王林", ({ "llkkjj", "wang lin", "wang" }));
	set("title", HIR"杀人魔"NOR);
	set("gender", "男性" );
	set("age", 26);
	set("str", 29);
	set("cor", 30);
	set("cps", 30);
	set("int", 20);
	set("long", @TEXT
他就是以嗜杀少年江湖人闻名的杀人魔王林,武功并不怎么出色,杀不了高
手,但杀高手的亲戚朋友,父母家人,大小老婆什么的还是绰绰有余
TEXT
);
	set("combat_exp", 100000);
	set("attitude", "heroism");
	set("force", 1000);
	set("max_force", 1000);
	set("mana", 1000);
	set("max_mana", 1000);
	set("atman", 1000);
	set("max_atman", 1000);
	set("force_factor", 5);
	set("mana_factor", 5);

	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 80);
	set_skill("literate", 60);
        set_skill("magic", 60);
        set_skill("force", 125);
        set_skill("spells", 80);
        
        set_skill("taoism", 60);
        set_skill("necromancy", 70);
        set_skill("gouyee", 50);
        
//        map_skill("magic", "taoism");
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
