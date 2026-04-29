#include <ansi.h>
inherit SKILL;

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("溜须拍马之术只能用学(learn)的来增加熟练度。\n");
}
string query_lev_desc(int level)
{
      return HIG "深浅难辨" NOR;
}

