// /d/xizang/class/dazhao/npc/gelun.c

inherit NPC;
inherit F_MASTER;
string ask_rujiao();
void kickout();
void create()
{
        set_name("葛伦", ({ "master gelun", "master","gelun" }) );
        set("gender", "男性" );
        set("age", 99);
        set("int", 30);
        set("apprentice_available", 20);
        create_family("大招寺", 20, "主持");
        set("long",
                "葛伦高僧早已坐化多年,你看到的其实是他的神识所化幻象。\n");

        set("inquiry", ([
               "入教": (: ask_rujiao :),
        ]) );
        set("combat_exp", 99999990);
        set("max_mana", 10000);
        set("mana", 20000);
        set("max_atman", 10000);
        set("atman", 20000);
        set("max_force", 10000);
        set("force", 20000);

        set_skill("literate", 200);
        set_skill("magic", 200);
        set_skill("zang-buddhi", 200);
        set_skill("essencemagic", 200);
        set_skill("space", 200);
        set_skill("notracesnow", 200);
        set_skill("yujiamu-quan", 200);
        set_skill("wuxinglun", 200);
        set_skill("jin-gang", 200);
        set_skill("banruo", 200);
        set_skill("bloodystrike", 200);
        set_skill("bolomiduo", 200);
        set_skill("cloudstaff", 200);
        set_skill("nutrifux", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);
        set_skill("staff", 200);
        set_skill("hammer", 200);
        set_skill("sword", 200);
        set_skill("strike", 200);
        set_skill("iron-cloth", 200);
        set_skill("mingwang-jian", 200);
        map_skill("force", "bolomiduo");
        map_skill("unarmed", "bloodystrike");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");
        map_skill("hammer", "wuxinglun");
        map_skill("strike", "nutrifux");
        map_skill("sword", "mingwang-jian");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: kickout :),
        }));
        set("chat_chance", 5);
        set("chat_msg", ({
                (: command, "consider" :),
                "大家明明都是佛教正宗,为什么中原武林总把我们当作邪派?",
                (: command, "sigh" :),
                "难道就是因为我们不戒荤食,不戒嫁娶?",
                (: command, "shake" :),
                "可是佛教本义并不要求素食和禁欲啊....."
        }));
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}

void attempt_apprentice(object ob)
{
        if(ob->query("class")!="lama") {
                command("say 我只收喇嘛教中人.");
                return;
        }

        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本主持今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
                command("smile");
                command("say 很好，很好，很好。");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
        add("apprentice_availavble", -1);
}

void kickout()
{
        object* obs;
        int i;

        obs=this_object()->query_enemy();
        for(i=sizeof(obs)-1;i>=0;i--) {
                message_vision("葛伦一脚把$N踢了出去\n", obs[i]);
                if(userp(obs[i])) 
                {
                        obs[i]->move("/d/xizang/class/dazhao/tower");
                        obs[i]->receive_damage("gin", 100);
                        obs[i]->receive_damage("kee", 200);
                        obs[i]->receive_damage("sen", 100);
                }
                else
                        destruct(obs[i]);
        }
}

void init()
{
        add_action("do_accept", "accept");
}

string ask_rupai()
{
        object me = this_player();

     if( me->query("class") != "lama")
     return "阁下并非我教中人，何必如此就遁入空门呢？";

     if( me->query_skill("zang-buddhi",1) < 220  )
     {       
     return "你的藏传佛法太低了，我教不收这等与佛祖无缘之人！";                      
     }   
     if( me->query("family/family_name") == "大招寺"  )
     {       
     return "你已经是我教中人，还瞎问什么！";                      
     }       
     command("heihei "+me->query("id"));
     command("nod "+me->query("id"));
     command("pat "+me->query("id"));
     command("say 既然你我都是佛门中人，想入西藏喇嘛教也是理所应当的事情，但是请你还是想好了再决定(accept)。\n");
                me->set_temp("ask_rupai",1);
}
int do_accept(string arg)
{
        object me = this_player();
                    
                if ( me->query_temp("ask_rupai",1) ) 
           {
                command("say 好吧，从今天起，你就是我大招寺中人了，你可想拜我为师？\n");
                me->set("family/family_name", "大招寺");
                return 1;
           }
           return 0;
}

