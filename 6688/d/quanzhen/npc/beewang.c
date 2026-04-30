inherit NPC;
void use_poison();

void create()
{
	set_name("蜂王",({"feng wang"}));
        set("race", "野兽");
        set("age", 4);
        set("yes_carry", 1);
	set("long","这是一只蜂王。\n");

        set("limbs", ({ "头部", "身体", "针刺" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 150);
        set("combat_exp", 1500);
        set("bellicosity", 300 );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );

        setup();
}
void use_poison()
{
        object *enemy, ob;
        // 2026-04-30: unused variable commented out
        // string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( ob->query_condition("bee_poison") ) return;

        tell_object(ob,
"你觉得脸上剧痛，伸手一摸发现一个小小的针刺。\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("bee_poison", 5);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}
