using System;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

using System.Data.SqlClient;
public partial class _Default : System.Web.UI.Page 
{
    public String strP = "";
    public static String shiJian = "";
    protected void Page_Load(object sender, EventArgs e)
    {
       
    }
    public static System.Data.DataSet RunQuery(String QueryString)
    {
        SqlDataAdapter DBAdapter;
        DataSet ResultDataSet = new DataSet();
        String ConnectionString = "Data Source=.\\SQLEXPRESS;AttachDbFilename=E:\\car\\App_Data\\dbCar.mdf;Integrated Security=True;Connect Timeout=30;User Instance=True";

        SqlConnection DBConnection = new SqlConnection(ConnectionString);
        try
        {//建立DataSet
            DBAdapter = new SqlDataAdapter(QueryString, DBConnection);
        }
        catch (Exception ex)
        {throw new Exception(ex.Message);
        } finally
        {DBConnection.Close();
        }
        return ResultDataSet;
    }
   
    protected void Button6_Click(object sender, EventArgs e)
    {
      
        String startCi = TextBox2_4.Text;
        String toCi = TextBox2_5.Text;
        String sql = "select * from tb_cityPo where staC= '" + startCi + "' and toC='" + toCi + "'";
        DataSet ds = RunQuery(sql);
        DataTable dt = ds.Tables[0];
        if (dt.Rows.Count==1)
        {
            //for (var j = 1;j<=7; j++)
            //{
            strP = strP + "," + dt.Rows[0]["x1"] + "|" + dt.Rows[0]["y1"] + ","+dt.Rows[0]["x2"] +
                "|" + dt.Rows[0]["y2"] + "," + dt.Rows[0]["x3"] + "|" + dt.Rows[0]["y3"] + "," + dt.Rows[0]["x4"] + "|" + dt.Rows[0]["y4"] + "," +
                dt.Rows[0]["x5"] + "|" + dt.Rows[0]["y5"]+"," +dt.Rows[0]["x6"] + "|" + dt.Rows[0]["y6"] + "," + dt.Rows[0]["x7"] + "|" + dt.Rows[0]["y7"];
           // }
            if (strP != null && !strP.Equals(""))
            {
                shiJian = "1";  //路线导航
              
            }
        }
    }

    protected void Button3_Click(object sender, EventArgs e)
    {
        strP = "";
        String GovName = TextBox1.Text;
        String sql = "select x,y from tb_gov where govName='" + GovName + "'";
        DataSet ds = RunQuery(sql);
        DataTable dt = ds.Tables[0];
        strP=strP+dt.Rows[0]["x"]+"|"+dt.Rows[0]["y"];
        if (strP.Length != 0) {
            shiJian = "2";  //划分行政单位
          }



    }
}
