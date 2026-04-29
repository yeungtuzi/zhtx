// replaced.c
// Update by dongsw@zhtx2 2002.8
// Function ansi_filter can use for ansi replace 
// Function replace_ansi can use for colorcat

#include <ansi.h>

inherit F_SAVE;
inherit F_DBASE;

void create()
{
        seteuid(getuid());
}

string ansi_filter(string text)
{
        if (! text)
                return "";

        text = replace_string(text, "$BLK$", BLK);
        text = replace_string(text, "$RED$", RED);
        text = replace_string(text, "$GRN$", GRN);
        text = replace_string(text, "$YEL$", YEL);
        text = replace_string(text, "$BLU$", BLU);
        text = replace_string(text, "$MAG$", MAG);
        text = replace_string(text, "$CYN$", CYN);
        text = replace_string(text, "$WHT$", WHT);
        text = replace_string(text, "$HIR$", HIR);
        text = replace_string(text, "$HIG$", HIG);
        text = replace_string(text, "$HIY$", HIY);
        text = replace_string(text, "$HIB$", HIB);
        text = replace_string(text, "$HIM$", HIM);
        text = replace_string(text, "$HIC$", HIC);
        text = replace_string(text, "$HIW$", HIW);
        text = replace_string(text, "$NOR$", NOR);

        text = replace_string(text, "$BBLK$", BBLK);
        text = replace_string(text, "$BRED$", BRED);
        text = replace_string(text, "$BGRN$", BGRN);
        text = replace_string(text, "$BYEL$", BYEL);
        text = replace_string(text, "$BBLU$", BBLU);
        text = replace_string(text, "$BMAG$", BMAG);
        text = replace_string(text, "$BCYN$", BCYN);
        text = replace_string(text, "$HBRED$", HBRED);
        text = replace_string(text, "$HBGRN$", HBGRN);
        text = replace_string(text, "$HBYEL$", HBYEL);
        text = replace_string(text, "$HBBLU$", HBBLU);
        text = replace_string(text, "$HBMAG$", HBMAG);
        text = replace_string(text, "$HBCYN$", HBCYN);

        text = replace_string(text, "$U$", U);
        text = replace_string(text, "$BLINK$", BLINK);
        text = replace_string(text, "$REV$", REV);
        text = replace_string(text, "$HIREV$", HIREV);
        text = replace_string(text, "$BOLD$", BOLD);

        return text;
}

string ansi_remove(string text)
{
        if (! text)
                return "";

        text = replace_string(text, BLK , "");
        text = replace_string(text, RED , "");
        text = replace_string(text, GRN , "");
        text = replace_string(text, YEL , "");
        text = replace_string(text, BLU , "");
        text = replace_string(text, MAG , "");
        text = replace_string(text, CYN , "");
        text = replace_string(text, WHT , "");
        text = replace_string(text, HIR , "");
        text = replace_string(text, HIG , "");
        text = replace_string(text, HIY , "");
        text = replace_string(text, HIB , "");
        text = replace_string(text, HIM , "");
        text = replace_string(text, HIC , "");
        text = replace_string(text, HIW , "");
        text = replace_string(text, NOR , "");

        text = replace_string(text, BBLK , "");
        text = replace_string(text, BRED , "");
        text = replace_string(text, BGRN , "");
        text = replace_string(text, BYEL , "");
        text = replace_string(text, BBLU , "");
        text = replace_string(text, BMAG , "");
        text = replace_string(text, BCYN , "");
        text = replace_string(text, HBRED , "");
        text = replace_string(text, HBGRN , "");
        text = replace_string(text, HBYEL , "");
        text = replace_string(text, HBBLU , "");
        text = replace_string(text, HBMAG , "");
        text = replace_string(text, HBCYN , "");

        text = replace_string(text, U , "");
        text = replace_string(text, BLINK , "");
        text = replace_string(text, REV , "");
        text = replace_string(text, HIREV , "");
        text = replace_string(text, BOLD , "");

        return text;
}
void replace_ansi(string file)
{
        if (previous_object())
                seteuid(geteuid(previous_object()));
        else
                seteuid(ROOT_UID);

        write(ansi_filter(read_file(file)));
}


