// abandon.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
       int i;
        mapping map_skill;
        string* base_skill, my_ad_pass;

        if( !arg || arg=="" ) return notify_fail("你要放弃哪一项技能？\n");
        if( arg=="banruo" )
         return notify_fail("龙象般若功学了就容入身体中去了，怎么能轻易放弃？\n");

          if( !me->query_skills(arg) ) return notify_fail("你并没有学过这项技能。\n");

        map_skill =  me->query_skill_map();
        if(map_skill) {
                        base_skill= keys(map_skill);
        for(i=0;i<sizeof(base_skill);i++) {
                if( map_skill[base_skill[i]] == arg) {
                        return notify_fail("你必须首先停止使用这项技能！\n");
                }
        } //end of for
        }//end of if

        write("\n请首先输入您的管理密码：");
        input_to("check_passwd", 1, me, arg);

        return 1;
}

void check_passwd(string pass, object me, string arg)
{
        string my_ad_pass;
        object link_ob;

        link_ob = me->query_temp("link_ob");
        my_ad_pass = link_ob->query("ad_password");

        if (! stringp(my_ad_pass) || crypt(pass, my_ad_pass) != my_ad_pass)
        {
                write("管理密码错误！\n\n");
                return;
        }

            if( !me->delete_skill(arg))
          {
                write("你并没有学过这项技能。\n");
                return;
            }
        write("\n你决定放弃继续学习" + to_chinese(arg) + "。\n");
}

int help()
{
        write(@TEXT
指令格式：abandon <技能名称>

放弃一项你所学的技能，注意这里所说的「放弃」是指将这项技能从你人物的资料中
删除，如果你已後还要练，必须从 0 开始重练，请务必考虑清楚。

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由於我们假设你
的人物随时都会从他／她的各种动作、战斗中学习，因此有些技能会因为你经常地使
用而出现在你的技能列表中，这个人物就必须花费一些精神去「记住」所学过的一切
，然而，人的资质各有不同，灵性高的人能够学习许多技能而成为多才多艺的才子，
灵性较差的人就只能专心於特定几项技能，如果你学的技能种类太多，超过你的灵性
，你会发现人物的学习速度将比只学几种技能的人慢，超过越多，学习效果低落的情
况越严重，这种情形就像是一个学期同时选修太多学分，虽然你仍然可以凭著超人的
意志力练下去，不过这将会多花费你许多宝贵的时间。
TEXT
        );
        return 1;
}


