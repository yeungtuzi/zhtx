//tangque.c
//written by masterall

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();
void use_poison();
void use_dart();

void create()
{
        set_name("唐缺", ({ "tang que", "que" }));
                set("long",
                "它是唐门新一代的后起之秀，现在唐门里里外外的事务基本都由它出面打理了。\n"
                "据说它的阴劲已然练到深不可测的地步，因此武林中也很少有人再敢来找唐门的麻烦。\n"
                "它看起来骠肥肚满，显然是过惯了优越的生活，皮肤细嫩得和少女一样。\n");
        set("title",HIR "唐门" NOR + GRN "少门主" NOR);
        set("nickname", HIB "劲霸天下" NOR);
        set("gender", "无性");
        set("age", 20);
        set("attitude", "friendly");

        set("str", 100);
        set("cps", 100);
        set("int", 100);
        set("cor", 100);
        set("con", 100);
        set("spi", 100);
        set("per", 1);
        set("kar", 30);
                                        
        set("kee",6000);
        set("max_kee", 6000);
        set("gin",3000);
        set("max_gin", 3000);
        set("sen",3000);
        set("max_sen", 3000);
        set("atman", 1000);
        set("max_atman", 1000);
        set("mana", 1000);
        set("max_mana", 1000);

        set("chat_chance_combat", 50);
                set("chat_msg_combat", ({
        //        (: perform_action , "throwing.mantian" :),
                (: use_poison :),
                (: use_dart :),
                }) );

                set("force", 10000);
                set("max_force", 5000);
                set("force_factor", 400);
                set("combat_exp", 10000000);
                set("score", 50000);

                set_skill("force", 220);
                set_skill("tangmen-xinfa", 220); 
                set_skill("move", 220);
                set_skill("dodge", 220);
                set_skill("claw", 220);
                set_skill("parry", 220);
                set_skill("yin-gong", 240);
                set_skill("dugong",250);
                set_skill("literate", 250);
                set_skill("tangshi-jian", 220);
                set_skill("mantian-huayu", 220);
                set_skill("throwing", 220);
                set_skill("sword", 220);
                set_skill("strike", 220);
                set_skill("tangmen-duzhang", 220);
                set_skill("taxue-wuhen", 220);

                map_skill("force", "yin-gong");
                map_skill("dodge", "yin-gong");
                map_skill("move", "yin-gong");
                map_skill("claw", "yin-gong");
                map_skill("throwing", "mantian-huayu");
                map_skill("sword", "tangshi-jian");
                map_skill("strike", "tangmen-duzhang");

                prepare_skill("claw", "yin-gong");

                create_family("唐门", 5, "弟子");
                set("class", "legend");

                set("shen_type",-1);

                set("shen",-50000000);
                set_temp("apply/attack", 100);
                set_temp("apply/armor_vs_force",100);
                set_temp("apply/armor",100);
                set_temp("apply/defense", 50);
                set_temp("apply/damage", 100);

                setup();
                carry_object("/d/tangmen/obj/jinyi")->wear();
}

                     

void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( ob->query_condition("tm_poison") ) return;

        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                {
                ob->apply_condition("tm_poison", 10);    
                tell_object(ob, "你觉得脸上一痒，似乎有什麽东西，伸手一摸却什麽也没有。\n");
        }
        return ;
}

void use_dart()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( random(query("combat_exp")) > (int)ob->query("combat_exp")/2 )
                {
                ob->set("kee", ob->query("kee")-40);    
                message_vision( "$N觉得身上一痒，伸手一摸，原来被唐缺的毒蒺藜打中了。\n",ob);
                if( !ob->query_condition("tm_poison") ) ob->apply_condition("tm_poison", 10);    
        }
        return ;
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "唐门")
        {
                command("say 我只收本门弟子，"+ RANK_D->query_respect(ob) + "可先加入唐门。\n");
                return;
        }
        if (    ob->query_skill("force",1) < 250 )
        {
                command("say "+ RANK_D->query_respect(ob) + "的内功基础还不够扎实，还需苦练才是。\n");
                return;
        } 
        if ((int)ob->query("shen") > -50000 )
        {
                command("say "+ RANK_D->query_respect(ob) + "还不够心狠手辣，不够资格做我的弟子。\n");
                return;
        }                                                            
                if ((string)ob->query("gender")=="无性")
        {
                command("hmm");
                command("shrug");
                command("say 好吧，我就收下你了。");
                command("say 既然你选择了这条不归路，可不要怪为师到时候对你心狠手辣，要求严格！");
                command("recruit " + ob->query("id"));
                        this_player()->set("class", "legend");
                this_player()->set("title",HIR "唐门" NOR + HIG +"护法" NOR);                  
                return ;
        }               
        command("say 我只收本门无性之人，"+ RANK_D->query_respect(ob) + "还是先考虑一下自己的性别问题怎么解决吧。\n。");
        return ;
}



