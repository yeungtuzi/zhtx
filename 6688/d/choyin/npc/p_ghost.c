// ghost.c

inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("琵琶鬼", ({ "pipa ghost", "ghost" }) );
        set("age", 30);
        
        set("str", 24);
        set("cor", 26);
        set("combat_exp",20000);
	set("max_force",5000);
        set("env/wimpy", 70);
        set_temp("apply/attack", 30);
        set_temp("apply/armor", 10);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_msg_combat",({
        (:command,"play pipa":),
        }));
        set_skill("dodge",100);
	set_skill("music",20);
        set_skill("unarmed",80);
        setup();
        carry_object(__DIR__"obj/pipa.c");
}

int is_ghost() { return 1; }
