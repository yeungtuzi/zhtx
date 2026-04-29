// /d/jingcheng/npc/doctor.c
// by dongsw in 2003.5.1 

// 今年5.1左右中国发生大规模的非典型性肺炎病情
// 特此制作他来纪念

inherit NPC;
#include <ansi.h>

int give_gift();

void create()
{
        set_name("纵横女郎中", ({"sars doctor", "doctor"}));
        set ("long", "\n她是非典时期的非典郎中。\n她负责为纵横的玩家发放非典预防药(gift)\n\n");
        set("gender", "女性");
        set("title",HIY"SARS"NOR);
        set("nickname", HIC" 预防非典 要从纵横抓起"NOR);
        set("age", 20);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([
                                "gift":(:give_gift:),
                                "礼物":(:give_gift:),
                        ]));
       setup();
}

int give_gift()
{
        object me=this_player();
        object ob=this_object();
        
        if (me->query("sars_pill")=="got" )
        {
                message_vision(CYN"$N对着$n摇了摇头。\n"NOR, ob, me);
                command("say 药固然好吃但是也不能多吃呀！");
                return 1;
        }
        
        if ((int)me->query("combat_exp")<100000 )
        {
                command("say 想吃我的药？你还不够资格！");
                return 1;
        }
        
        if ((int)me->query("sars/answer_wrong") > 2 )
        {
                command("say 你这个笨蛋，居然连续三次回答错误，i fule u，还想吃药？去死吧！smash");
                return 1;
        }        
        
        write(REF CYN"\n纵横女郎中说道：想要礼物可以，不过现在处于非典时期，你要回答对我三个问题才可以。\n\n"
                 HIY"第一问：预防SARS在游戏地点上要注意什么？\n\n"NOR
                 CYN"a.可以去封闭式网吧，但要带潜水氧气桶。\n\n"
                 "b.尽量在家玩游戏，少去封闭式网吧。\n\n"
                 "c.憋气！！忍不住时在冲出去...呼~~\n\n"
                 "d.我不怕！！因为我不用肺呼吸！！\n\n"NOR
                 "你选择？（直接输入a.b.c.d)："NOR
        );
        input_to("ask_2", me);
        return 1;
}

void ask_2(string answer, object me)
{
        if(answer == "a" || answer == "c" || answer == "d")
        {
                write(CYN"\n纵横女郎中说道：回答错误！这么简单的问题都回答不对，还想吃我的药？门都没有！\n"NOR);
                command("kick " + me->query("id"));
                me->add("sars/answer_wrong",1);
                write(CYN"\n纵横女郎中说道：你已经回答错误" + chinese_number(me->query("sars/answer_wrong")) + "次了！\n"NOR);
                return;
        }
        else if(answer == "b")
        {
                write(REF CYN"\n纵横女郎中说道：不错，不错，答对了，听好下一问。\n\n"
                         HIY"第二问：预防SARS在饮食方面要注意什么？\n\n"NOR
                        CYN"a.大口喝酒，大口吃肉，高兴就好！\n\n"
                        "b.均衡饮食、补充营养与适量运动。\n\n"
                        "c.我是神！！我不食人间烟火！！\n\n"
                        "d.都吃，就是不吃亏！\n\n"NOR
                        "你选择？（直接输入a.b.c.d)："NOR
                );
                input_to("ask_3", me);
        }
        else
        {
                write("请在(a,b,c,d)四个答案种选择，你选择？\n");
                input_to("ask_2", me);
        }
}

void ask_3(string answer, object me)
{
        if(answer == "a" || answer == "c" || answer == "d")
        {
                write(CYN"\n纵横女郎中说道：回答错误！这么简单的问题都回答不对，还想吃我的药？门都没有！\n"NOR);
                command("kick " + me->query("id"));
                me->add("sars/answer_wrong",1);
                write(CYN"\n纵横女郎中说道：你已经" + chinese_number(me->query("sars/answer_wrong")) + "次回答错误了！\n"NOR);                
                return;
        }
        else if(answer == "b")
        {
                write(REF CYN"\n纵横女郎中说道：不错，不错，答对了，听好下一问。\n\n"
                         HIY"最后一问：下列关于SARS的说法哪个是正确的？\n\n"NOR
                        CYN"a.抽烟啦，听说抽烟可以预防SARS的哦~~\n\n"
                        "b.我在家呆着不出门了，反正吃的用的都有，天天上线玩纵横啦~~\n\n"
                        "c.戴一个大大大的口罩，把整个脸都包起来……\n\n"
                        "d.勤洗手，喝有预防效果的中药，去人多的场所时戴大小合适的口罩。\n\n"NOR
                        "你选择？（直接输入a.b.c.d)："NOR
                );
                input_to("ask_4", me);
        }
        else
        {
                write("请在(a,b,c,d)四个答案种选择，你选择？\n");
                input_to("ask_3", me);
        }
}

void ask_4(string answer, object me)
{
        object obj = new("/d/jingcheng/npc/obj/pill.c");

        if(answer == "a" || answer == "b" || answer == "c")
        {
                write(CYN"\n纵横女郎中说道：回答错误！这么简单的问题都回答不对，还想吃我的药？门都没有！\n"NOR);
                command("kick " + me->query("id"));
                me->add("sars/answer_wrong",1);
                write(CYN"\n纵横女郎中说道：你已经" + chinese_number(me->query("sars/answer_wrong")) + "次回答错误了！\n"NOR);
                return;
        }
        else if(answer == "d")
        {
                write(CYN"\n纵横女郎中说道：不错，不错，都答对了。来，这个给你!\n"NOR
                         "纵横女郎中给了你一片SARS预防专用药（纵横版）\n"
                      CYN"纵横女郎中说道：快吃了吧，希望对你有所帮助，一定要留心非典哦，希望你有个欢乐、祥和的五一假期！\n"NOR);
                obj->set("owner", me);
                obj->move(me);
                me->set("sars_pill", "got");
        }
        else
        {
                write("请在(a,b,c,d)四个答案种选择，你选择？\n");
                input_to("ask_3", me);
        }
}

