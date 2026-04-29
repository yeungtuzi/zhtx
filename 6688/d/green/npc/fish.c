
inherit NPC;

void create()
{
        set_name("银鱼", ({ "fish" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一条鱼头鱼脑的银鱼\n");
        set("max_kee", 1);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 80);

        setup();
}

void die()
{
        object ob;
        message_vision("$N肚皮一翻，死了。\n", this_object());
        ob = new(__DIR__"yurou");
        ob->move(environment(this_object()));
        destruct(this_object());
}
   