// dfbb.c 东方不败
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("东方不败", ({ "dong fang bu bai", "dong","dfbb" }));
        //set("nickname", "日月神教教主");
        set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "教主");
        set("long", "他就是日月神教教主东方不败\n
                可是他看起来貌美如花,国色天香\n");
        set("gender", "中性");
        set("age", 30);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 28);
          set("dex", 58);
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                ("\n"+ RED "东方不败说道：嘿嘿,武功不错啊！\n\n" NOR),
                (: exert_function, "kuihua" :),
                (: exert_function, "recover" :),
        }) );

        set("max_kee", 2000);
        set("max_gin", 2000);
        set("atman", 300);
        set("max_atman", 300);
        set("mana", 300);
        set("max_mana", 300);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 80);
        set("combat_exp", 1000000);
        set("score", 1000000);

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("kuihua-shengong", 100);
        set_skill("dodge", 100);
        set_skill("mo-zhang-jue", 100);
        set_skill("strike", 100);
        set_skill("mo-jian-jue", 100);
        set_skill("pixie-sword", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("literate", 100);
        set_skill("daguanming",100);

        map_skill("force", "kuihua-shengong");
        map_skill("strike", "mo-zhang-jue");
        map_skill("parry", "pixie-sword");
        map_skill("sword", "pixie-sword");
        map_skill("dodge", "kuihua-shengong");

        prepare_skill("strike", "mo-zhang-jue");

        create_family("日月神教", 1, "教主");
        setup();

        carry_object("/class/heimuya/obj/dress")->wear();
        carry_object("/class/heimuya/obj/flower_boot")->wear();
        carry_object("/class/heimuya/obj/needle")->wield();
}

void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
        object me, room1;
        if( !ob || !objectp(ob) ) return;
        me = this_object();
        room1 = environment(me);

        if (room1->query("no_fight"))
                room1->set("no_fight", 0);

        if (interactive(ob))
        {
                command("say 你是什么人，竟敢擅闯本教重地，给我去死吧！\n");
//                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        }       

}


void die()
{
       message_vision(YEL"\n只见“东方不败”虽然跪倒在地，磕头如捣蒜，\n"NOR,this_object());                
       message_vision(YEL"“这位大侠饶命啊！小的只是奉命行事，迫不得以而为之！你看我身子都残了，放小的一条生路吧！”\n"NOR,this_object());            
        message_vision(HIG"$N"+YEL"哀嚎一声，死了！原来这家伙竟是个冒牌的！"NOR, this_object());
        ::die();
}

