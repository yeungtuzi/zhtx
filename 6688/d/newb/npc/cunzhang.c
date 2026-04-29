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
        set_name("老村长", ({ "cun zhang","lao","老村长"}) );
        set("gender", "男性" );
        set("age", 66);
        set("long","这就是新手村的老村长。他面色红润，精神矍铄，为了建好新手村，几乎倾家荡产。\n"
                                                +"在他的影响下，村民们个个都非常热情好客。\n");
        set("combat_exp", 6000);
        set("inquiry",([
                                "出村"  :(:ask_me:),
                                "新手村" : "新手村是新手们的乐园啊，等你的经验到了一定水平就可以出村了。",
                                "介绍信" : (:ask_me:),
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

void greeting(object ob)
{
                int exp;
        if( !ob || environment(ob) != environment() ) return;
        exp=ob->query("combat_exp");

        if(ob->query("eff_kee")<ob->query("max_kee")) {
                        message_vision(CYN"老村长看了$N一眼，关切的说道：受伤了？赶快包扎伤口吧。你\n"
                        +"可以从布衣上撕条布下来包扎。"HIW+" tear cloth "NOR+CYN"，然后"HIW+" bandage "NOR+CYN"就\n"
                        +"可以了。帮别人包扎是"HIW+" bandage <别人的id> "NOR+CYN"。\n"NOR,ob);
                        return;
                }

                if(exp<20000) {
                tell_object(ob,YEL"老村长慈祥的拍了拍你的头，对你说道：新来的吧？\n"
                +"你可以先用"HIW+" look "NOR+YEL"指令来看看周围的东西，用"HIW+" hp "NOR+YEL"指令"
                +"来查看自己的状态。\n"
                +"如果不清楚的话，你可以用"HIW+" help look "NOR+YEL"和"HIW+" help hp "NOR+YEL"来得到帮助。\n"
                +"要去别的地方的话，输入方向就可以了，比如"HIW+" west "NOR+YEL"或者"HIW+" w "NOR+YEL"。其他方向也一样，\n"
                +"比如"HIW+" n, e, s, ne, se, nw, sw "NOR+YEL"等等。\n"
                NOR);
                }

}

int ask_me()
{
        object who, letter;
        int exp;
        who=this_player();
        exp=who->query("combat_exp");

        if(exp<50000) {
                        message_vision(CYN"老村长对$N说：你还是多在新手村里锻炼锻炼吧。\n"NOR,who);
                        return 1;
                }

        if ( who->query_temp("marks/chuchun") ){
                        message_vision(CYN"老村长对$N说：你快去吧，别罗罗嗦嗦的。\n"NOR,who);
                        return 1;
                }
        who->set_temp("marks/chuchun",1);
        letter=new(__DIR__"obj/letter");
        letter->move(who);
        command("smile");
        message_vision(HIG"老村长慈祥的笑着，对$N说：好孩子，有出息！\n"NOR,who);
        message_vision("老村长给了$N一封介绍信。\n"NOR,who);
        message_vision(HIG"老村长对$N说：你拿这封介绍信，到村西口坐船到附近的一个小岛，\n"
        +"穿过岛中的洞穴，就会见到我哥哥了。把信给他，他会告诉你怎么\n"
        +"出村的。一路上遇到困难，可不要气馁哦。\n"NOR,who);

}
