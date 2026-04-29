
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("守城官兵", ({ "town guard", "guard" }) );
        set("long",
                "这是个正在这里站岗的守城官兵，虽然和许多武林人物比起来，官兵\n"
                "们的武功实在稀松平常，但是他们是有组织、有纪律的战士，谁也不\n"
                "轻易地招惹他们。\n");

        set("attitude", "peaceful");
        set("vendetta_mark", "authority");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 100000);
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "守城官兵喝道：还不快放下武器束手就缚？\n",
                "守城官兵喝道：大胆刁民！竟敢杀官造反？\n"
        }) );

        set_skill("unarmed", 70);
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 100);

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object("/obj/cloth/suit")->wear();
        carry_object("/obj/weapon/longsword")->wield();
}

void init()
{
        mapping mine;
        object ob, room;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
        ob = this_player();
        if(userp(ob)&&!ob->query_temp("armor/cloth") && !ob->query_temp("armor/waist") )
        {
               command("say 大胆狂徒，光天化日之下竟敢赤身裸体，哪里逃!\n");
		ob->move("/d/wizard/prizon");
        }
        return ;           
}
