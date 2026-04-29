// /d/xizang/class/hama/npc/hamawang.c

inherit NPC;

void use_poison();
void create()
{
        set_name("大癞蛤蟆王", ({ "hamawang", "wang" }));
        set("gender", "男性" );
        set("age", 99);
        set("str", 30);
        set("long", @LONG
这是传说中修练千余年成精的大癞蛤蟆王.
LONG
);

	set("shen", -100000);
        set("attitude", "heroism");
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 20);
        set("combat_exp", 9600000);
	set("pursuer", 1);
	set_skill("move", 180);
        set_skill("dodge", 150);
        set_skill("unarmed", 120);
        set_skill("force", 140);
        set_skill("parry", 150);
        set_skill("hamagong", 140);
        set_skill("chanchu-bufa", 150);
        map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("move", "chanchu-bufa");
        set("chat_chance_combat", 65);
        set("chat_msg_combat", ({
                "大癞蛤蟆王用谁也听不懂的语言怪叫着:呱呱呱~~~~$@#!\n",
                (: use_poison :),
        }) );
        setup();
}

void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        tell_object(ob,"大癞蛤蟆王怪叫一声,一股毒液从口中射出!\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("hama_poison", 
                (int)this_player()->query_condition("hama_poison")
                + random(13)+12);
}
