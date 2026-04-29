// /d/peking/npc/student.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("学生", ({ "student", "xuesheng", "tongxue" }) );
        if(random(10)< 6)
            set("gender", "男性" );
        else
            set("gender", "女性" );
        set("age", 14 + random(11) );
        set("long","一个普普通通的大学生.\n");
        set("combat_exp", 200000);
        set("chat_chance",15);
        set("chat_msg",({
        "这位同学对你笑笑说:你好!\n",
        (: random_move :)
                }));
        set_skill("literate", 50 + random(80) );
        set_skill("computer", 10 + random(80) );

        set("inquiry", ([
                "mscat": "这只猫我见过,不过我不知道他在哪里.",
               "流浪猫": "这只猫我见过,不过我不知道他在哪里.",
                 "网络": "网络费太贵啦!",
                 "上网": "一定要搞个免费的账号才行",
        ]) );
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}

