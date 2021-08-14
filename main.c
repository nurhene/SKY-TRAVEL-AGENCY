/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include"Conversion_needed.h"
#include <gtk/gtk.h>
#include"callbacks.h"
#include "interface.h"
#include "support.h"
#include "callbacks.h"


#include"Users.h"
#include"Verif_login.h"
#include"Conversion_needed.h"
#include"Admin.h"
#include"Agent.h"
#include"Catalogues.h"
   GtkWidget *MainMenu;
void afficher_catalogue(GtkWidget *viewport_Catalogue)
{
GtkWidget *Table_show_Catalogues ;
struct Catalogue_Hotel Catalogues[200];
int nb_cat=0,i,j;
FILE *f;
f=fopen("/home/bouzayen/Desktop/Skytravel/Catalogue.bin","rb");
if(f!=NULL)
{	nb_cat=0;
		while(!(feof(f)))
		{nb_cat++;
	fread(&Catalogues[nb_cat],1,sizeof(Catalogues[nb_cat]),f);
				
		}
	fclose(f);
}
g_print("Nb de Catlo %d",nb_cat);

 Table_show_Catalogues = gtk_table_new (nb_cat-1, 5, FALSE);
  gtk_widget_show (Table_show_Catalogues);
  gtk_container_add (GTK_CONTAINER (viewport_Catalogue), Table_show_Catalogues);
f=fopen("/home/bouzayen/Desktop/Skytravel/Catalogue.bin","rb");
if(f!=NULL)
{
i=1;
GtkWidget *Labels_catalogue[200][5];
GtkWidget *image[200],*button[200];
char *buffer;
const GdkPixbuf *pb ;char date[220];
g_print("\nGetting in while %d",i);
while(i<nb_cat)
	{
g_print("\n In While iti : %d",i);
fread(&Catalogues,1,sizeof(Catalogues[i]),f);;
   /*****Image*******/
	j=0;
  image[i] = create_pixmap (MainMenu,Catalogues[i].Image_path );
  gtk_widget_show (image[i]);
GdkPixbuf *pb = gtk_image_get_pixbuf(GTK_IMAGE(image[i] ));
 //gdk_pixbuf_get_width(pb)/gdk_pixbuf_get_height(pb));
  gtk_table_attach (GTK_TABLE (Table_show_Catalogues), image[i], j, j+1, i, i+1,(GtkAttachOptions) (GTK_EXPAND | GTK_FILL),(GtkAttachOptions) (GTK_EXPAND), 0, 0);
//Sizeing image
  gtk_widget_set_size_request (image[i], gdk_pixbuf_get_width(pb), gdk_pixbuf_get_height(pb));
   /*****Tille*******/
	j=1;
Labels_catalogue[i][j]=gtk_label_new (Catalogues[i].Title);
	gtk_widget_show (Labels_catalogue[i][j]);
  	gtk_table_attach (GTK_TABLE (Table_show_Catalogues), Labels_catalogue[i][j], j, j+1, i, i+1,(GtkAttachOptions) (GTK_EXPAND | GTK_FILL),(GtkAttachOptions) (GTK_EXPAND), 0, 0);



   /*****Date de Début*******/
	j=3;
strcpy(date,"Du ");
buffer=i_to_a((Catalogues[i].date_debut.jour));
strcat(date,buffer);
strcat(date,"/");
buffer=i_to_a((Catalogues[i].date_debut.mois));
strcat(date,buffer);
strcat(date,"/");
buffer=i_to_a((Catalogues[i].date_debut.anne));
strcat(date,buffer);
Labels_catalogue[i][j]=gtk_label_new (date);
	gtk_widget_show (Labels_catalogue[i][j]);
  	gtk_table_attach (GTK_TABLE (Table_show_Catalogues), Labels_catalogue[i][j], j, j+1, i, i+1,(GtkAttachOptions) (GTK_EXPAND | GTK_FILL),(GtkAttachOptions) (GTK_EXPAND), 0, 0);
   /*****Date de fin*******/
	j=4;
strcpy(date,"Au ");
buffer=i_to_a((Catalogues[i].date_fin.jour));
strcat(date,buffer);
strcat(date,"/");
buffer=i_to_a((Catalogues[i].date_fin.mois));
strcat(date,buffer);
strcat(date,"/");
buffer=i_to_a((Catalogues[i].date_fin.anne));
strcat(date,buffer);
Labels_catalogue[i][j]=gtk_label_new (date);
	gtk_widget_show (Labels_catalogue[i][j]);
  	gtk_table_attach (GTK_TABLE (Table_show_Catalogues), Labels_catalogue[i][j], j, j+1, i, i+1,(GtkAttachOptions) (GTK_EXPAND | GTK_FILL),(GtkAttachOptions) (GTK_EXPAND), 0, 0);

   /*****Descreption*******/
	j=5;
Labels_catalogue[i][j]=gtk_label_new (Catalogues[i].Description);
	gtk_widget_show (Labels_catalogue[i][j]);
  	gtk_table_attach (GTK_TABLE (Table_show_Catalogues), Labels_catalogue[i][j], j, j+1, i, i+1,(GtkAttachOptions) (GTK_EXPAND | GTK_FILL),(GtkAttachOptions) (GTK_EXPAND), 0, 0);
gtk_widget_set_size_request (Labels_catalogue[i][j],250,75);
   /*****Prix*******/
	j=2;
buffer= (i_to_a((Catalogues[i].Prix_ch_simple_1pers)));
strcat(buffer," Dt");
Labels_catalogue[i][j]=gtk_label_new (buffer);
	gtk_widget_show (Labels_catalogue[i][j]);
  	gtk_table_attach (GTK_TABLE (Table_show_Catalogues), Labels_catalogue[i][j], j, j+1, i, i+1,(GtkAttachOptions) (GTK_EXPAND | GTK_FILL),(GtkAttachOptions) (GTK_EXPAND), 0, 0);

//g_print("Le prix de %d est = %s",i,buffer);

/*****Bouton Consulter*******/
	j=6;
button[i]=gtk_button_new_with_mnemonic (_("Consulter"));
gtk_widget_show (button[i]);
gtk_table_attach (GTK_TABLE (Table_show_Catalogues), button[i], j, j+1, i, i+1,(GtkAttachOptions) (GTK_EXPAND | GTK_FILL),(GtkAttachOptions) (GTK_EXPAND), 0, 0);

  g_signal_connect ((gpointer) button[i], "clicked",
                    G_CALLBACK (on_Consulter_Catalogues_clicked),
                    Catalogues[i].Title);
i++;
  /*g_signal_connect ((gpointer) buttonSignin, "clicked",
                    G_CALLBACK (on_buttonSignin_clicked),
                    NULL);*/
		}//while
}//if

  gtk_widget_show (viewport_Catalogue);


}
int
main (int argc, char *argv[])
{


#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory ("/home/bouzayen/Desktop/Skytraveltodo/SkyTravel/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  MainMenu = create_MainMenu ();
/**********************************************************/
GtkWidget *viewport_Catalogue,*Table_show_Catalogues;
viewport_Catalogue=lookup_widget(MainMenu,"viewport_Catalogue");

(afficher_catalogue(viewport_Catalogue));
/********************************************************************/


  gtk_widget_show (MainMenu);
   
   GtkWidget *Login_inteface;
   GtkWidget *Signup_interface;
   GtkWidget *Admin_interface;
   GtkWidget *Users_Gesture_interface;
   GtkWidget *Agents_Gesture_interface;
   GtkWidget *Gestion_des_Prestations;
   GtkWidget *Claim_Gesture_Interface;
   GtkWidget *Agents_inteface;
  GtkWidget *dialogPassword_Error;
  //MainMenu = create_MainMenu ();
 // gtk_widget_show (MainMenu);
  Login_inteface = create_Login_inteface ();
  Signup_interface = create_Signup_interface ();
  Admin_interface = create_Admin_interface ();
  Users_Gesture_interface = create_Users_Gesture_interface ();
  Agents_Gesture_interface = create_Agents_Gesture_interface ();
  Gestion_des_Prestations = create_Gestion_des_Prestations ();
  Claim_Gesture_Interface = create_Claim_Gesture_Interface ();
  Agents_inteface = create_Agents_inteface ();
  
  

  gtk_main ();
  return 0;
}

