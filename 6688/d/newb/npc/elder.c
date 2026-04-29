///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit NPC;

int ask_me();

void create()
{
        object ob;
        set_name("老者", ({ "elder","lao","老者"}) );
        set("gender", "男性" );
        set("age", 71);
        set("long","一位须发尽白的老者。听说他是新手村老村长的哥哥，也是真正的新手村建设的总策划。\n");
        set("combat_exp", 12800000);
        set("inquiry",([
                                "飞离尘世"  :(:ask_me:),
        ]));

        carry_object("/obj/cloth")->wear();
        setup();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object who)
{
                int exp, i, hasletter;
                object flybag;
                object *inv;
                if( !who || environment(who) != environment() ) return;
                inv = all_inventory(who);
                                        for( i=0;i<sizeof(inv);i++) {
                                              if( inv[i]->query("name")=="出村介绍信")
                                               {hasletter=1;
                                                 destruct(inv[i]);
                                                 }
                }
                exp=who->query("combat_exp");
                if(!hasletter) {
                        message_vision(HIY"老者对$N说：咦，你没去问老村长要介绍信？\n"NOR,who);
                        return;
                }
                if(exp<50000) {
                        message_vision(HIY"老者对$N说：咦，你怎么跑这儿来了？\n"NOR,who);
                        return;
                }
                if ( !who->query_temp("marks/chuchun") ){
                        message_vision(CYN"老者对$N说：咦，从哪儿骗来的介绍信？\n"NOR,who);
                        return;
                }

        who->delete_temp("marks/chuchun");
        who->set("marks/出村",1);
        message_vision("$N把手中的出村介绍信递给老者。\n"NOR,who);
        message_vision("老者从$N手中接过介绍信，拆开看了一眼，点了点头。\n"NOR,who);
        flybag = new("/d/sky/obj/flybag.c");
                flybag->move(who);

//写一段出村前的送行话，介绍f'l'y'ba'g，
        message_vision(YEL"老者慈祥的拍了拍$N的头，对$N说道：你可以离开新手村，到江湖中闯荡了。\n"
                +"这个飞行包送给你了，用它"HIW+" flyup "NOR+YEL"就可以离开这儿了。\n"
                +"用飞行包可以直接到很多地方。另外飞行包还可以"HIW+" patit "NOR+YEL"，很有用。\n"
                +"行走江湖，要多注意安全，你不妨看看"HIW+" help safety "NOR+YEL"。\n"
                +"另外，多多和其他江湖侠客沟通，你可以用"HIW+" help goutong "NOR+YEL"来了解更多。\n"
                +"还有，"HIW+" help "NOR+YEL"一定要多看看。\n"NOR,who);
        message_vision("老者给了$N一个飞行包。\n"NOR,who);
        command("wave "+who->query("id"));
        return;
}

int ask_me()
{
        message_vision(CYN"老者对$N说：咦，你怎么知道我的真名？\n"NOR,this_player());
                        return 1;
}
