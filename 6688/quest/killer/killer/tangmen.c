#include "skillslv.h"

inherit "quest/killer/killer.c";

void use_poison();
void use_dart();
void cui_poison();

void set_skills()
{
        ::set_skills();
        set("shen_type",-1);
        create_family("唐门", 8, "弟子");
        set_skill("force", LV);
        set_skill("sword", LV);
        set_skill("throwing", LV);
        set_skill("parry", LV);
        set_skill("dodge", LV);
        set_skill("move", LV);
        set_skill("strike",LV);
        set_skill("tangmen-xinfa", LV);
        set_skill("tangshi-jian", LV);
        set_skill("mantian-huayu", LV);
        set_skill("taxue-wuhen", LV);
        set_skill("tangmen-duzhang",LV);
        set_skill("dugong",LV);
        set_skill("claw",LV);
        set_skill("yin-gong",LV);
        map_skill("claw", "yin-gong");
        map_skill("parry", "yin-gong");
        map_skill("dodge", "yin-gong");
//        map_skill("dodge", "taxue-wuhen");
        map_skill("force", "tangmen-xinfa");
        map_skill("sword", "tangshi-jian");
//        map_skill("parry", "tangshi-jian");
        map_skill("strike", "tangmen-duzhang");
        map_skill("throwing", "mantian-huayu");

//        prepare_skill("strike", "tangmen-duzhang");
        prepare_skill("claw", "yin-gong");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: use_poison :),
                (: use_dart :),
                (: cui_poison :),
                (: perform_action , "throwing.mantian" :)
        }) );

        carry_object("/d/tangmen/obj/jinyi")->wear();
        carry_object("/d/tangmen/obj/dujili")->wield();

}

/*
void heart_beat() {
   if (!query_temp("jiuyang-shield") && is_fighting())
      command("exert jiuyang-shield");
      ::heart_beat();
}
*/
void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                {
                ob->apply_condition("tm_poison", random(10)+ob->query_condition("tm_poison"));
                tell_object(ob, "你觉得脸上一痒，似乎有什麽东西，伸手一摸却什麽也没有。\n");
                ob->update_condition("tm_poison", random(2));
        }
        return ;
}

void use_dart()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                {
                ob->set("kee", ob->query("kee")-40);
                message_vision( "$N觉得身上一痒，伸手一摸，原来被唐宏的毒蒺藜打中了。\n",ob);
                ob->apply_condition("tm_poison", random(10)+ob->query_condition("tm_poison"));
                ob->update_condition("tm_poison", random(2));
        }
        return ;
}

void cui_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( ob )        command("exert quickpoison "+ob->query("id"));

        return ;
}
