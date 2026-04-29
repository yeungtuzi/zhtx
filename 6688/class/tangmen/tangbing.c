// tangbing.c
// written by tang

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void use_poison();
void use_dart();

void create()
{
        set_name("唐冰", ({ "tang bing", "bing" }) );
        set("title",HIR"唐门护法"NOR);
        set("nickname", RED"三手剑客"NOR);
        set("gender", "男性");
        set("age", 50);
        set("long", "他是唐门门主的哥哥，现任唐门护法，加入唐门必须问他。\n");          

        set("attitude", "peaceful");
        set("class", "legend");

        set("str", 20 + random(16));
        set("cps", 20 + random(16));
        set("int", 20 + random(16));
        set("cor", 20 + random(16));
        set("con", 20 + random(16));
        set("spi", 20 + random(16));
        set("per", 20 + random(16));
        set("kar", 20 + random(16));
                                        
        set("kee",1000);
        set("max_kee", 1000);
        set("gin",500);
        set("max_gin", 500);
        set("sen",500);
        set("max_sen", 500);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 100);
        set("max_mana", 100);

        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 60);

        set("combat_exp", 200000);
        set("score", 5000);
        set("shen_tyep",-1);

        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("throwing", 120);
        set_skill("parry", 100);
        set_skill("dodge", 100);                            
        set_skill("move", 100);
        set_skill("strike",100);
        set_skill("dugong", 120);
        set_skill("literate", 100);

        set_skill("tangmen-xinfa", 100);
        set_skill("tangshi-jian", 100);
        set_skill("mantian-huayu", 120);
        set_skill("taxue-wuhen", 80);
        set_skill("tangmen-duzhang",100);

        map_skill("dodge", "taxue-wuhen");
        map_skill("move", "taxue-wuhen");
        map_skill("force", "tangmen-xinfa");
        map_skill("sword", "tangshi-jian");
        map_skill("parry", "tangshi-jian");   
        map_skill("strike", "tangmen-duzhang");
        map_skill("throwing", "mantian-huayu");

        prepare_skill("strike","tangmen-duzhang");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                "唐冰脚步轻移，左手轻弹。\n",
                "唐冰左手一扬，从袖中射出一颗毒蒺藜。\n",
                (: use_poison :),              
                (: use_dart :),
                (: perform_action , "throwing.mantian" :)
        }) );

        create_family("唐门", 4, "护法");

        set_temp("apply/defense", 100);
        set_temp("apply/attack",50);

        setup();

        carry_object("/d/tangmen/obj/jinyi")->wear();
        carry_object("/d/tangmen/obj/dujili")->wield();
}

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
                message_vision( "$N觉得身上一痒，伸手一摸，原来被唐冰的毒蒺藜打中了。\n",ob);
                ob->apply_condition("tm_poison", random(10)+ob->query_condition("tm_poison"));    
                ob->update_condition("tm_poison", random(2));    
        }
        return ;
}

void attempt_apprentice(object ob)
{
        if ( (string)this_player()->query("gender")=="男性" )
                command("say 我不收弟子，"+ RANK_D->query_respect(ob) + "可先加入唐门, 然后拜剑儿为师。");
        if ( (string)this_player()->query("gender")=="女性" )
                command("say 我不收弟子，"+ RANK_D->query_respect(ob) + "可先加入唐门, 然后拜方儿为师。");
        return ;
}

void init()
{
        object who = this_player();
        
        if( who->query("family/family_name") == "唐门" && who->query("family/generation") <= 1 )
        {
                who->set("family/generation",6);                        
        }                 
        add_action("do_join", "join");
                
}

int do_join(string arg)
{
        object who,ob;

        who=this_player();        

        if ( arg!="唐门" )      return  notify_fail("你要加入什么!\n");
        
        if ((string)who->query("family/family_name") == "唐门")
        {
                ob=present("glove",who);
                if (!ob)
                {
                        ob=new("/d/tangmen/obj/glove");
                        ob->move(who);  
                        tell_object(who,"手套弄丢了，下次小心点！\n");
                }        
                return  notify_fail("你已是唐门人。\n");
        }
        
        if ( (string)who->query("gender")=="无性")      
                return notify_fail("本门不收太监, 公公请另投名师!\n");

        if ( who->query("betrayer") )
                return notify_fail("你反复无常，唐门岂能容你！\n");

        if( who->query("family") && who->query("family/family_name")!="唐门" )  
        {
//              who->add("betrayer", 1);
//              who->delete("faith");
                write("唐门不收别派叛徒！\n");
                return 1;
        }

        who->set("family/family_name","唐门");          
        who->set("family/generation",6);          
        if ( (string)who->query("gender")=="男性")      
                who->set("title",HIR"唐门"NOR+GRN"家丁"NOR);   
        else    who->set("title",HIR"唐门"NOR+GRN"女仆"NOR);   

        ob=present("glove",who);
        if (!ob)
        {
                ob=new("/d/tangmen/obj/glove");
                ob->move(who);  
        }        
        message_vision("恭喜$N加入唐门。\n", who);  
        who->set("class","legend");
        who->delete("family/master_id");
        who->delete("family/master_name");
        return 1;                                             
}
                                                        

